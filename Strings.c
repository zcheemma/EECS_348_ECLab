#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

double extractNumeric(const string& str) {
    bool neg_num = false;
    bool currDecimal = false;
    double total = 0.0;
    double decimal = 0.1;

    if (str.empty()) {
        return -999999.99;
    }

    size_t i = 0;
    if (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            neg_num = true;
        }
        i++;
    }

    for (; i < str.size(); i++) {
        if (isdigit(str[i])) {
            if (currDecimal) {
                total += (str[i] - '0') * decimal;
                decimal /= 10.0;
            } else {
                total = total * 10 + (str[i] - '0');
            }
        } else if (str[i] == '.' && !currDecimal) {
            currDecimal = true;
        } else {
            return -999999.99;
        }
    }

    if (neg_num) {
        total = -total;
    }

    return total;
}

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        // Check for "END" to terminate
        if (input == "END") {
            break;
        }

        // Check for length limit
        if (input.length() > 20) {
            cout << "The input is invalid." << endl;
            continue;
        }

        double number = extractNumeric(input);

        if (number == -999999.99) {
            cout << "The input is invalid." << endl;
        } else {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        }
    }

    return 0;
}
