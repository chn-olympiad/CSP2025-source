#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string a;
    cin>>a;
    vector<char> numbers;

    for (int i = 0; i < a.size(); i++) {
        if (isdigit(a[i])) {
            numbers.push_back(a[i]);
        }
	}

    sort(numbers.begin(), numbers.end(),
         [](char b, char c){
            return b > c;
        }
    );

    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i];
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
