#include <bits/stdc++.h>
using namespace std;
string s;
vector<char> numbers;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int sSize = s.size();
    for (int i = 0; i < sSize; i++) {
        if (48 <= s[i] && s[i] <= 57) numbers.push_back(s[i]);
    }
    sort(numbers.begin(), numbers.end());
    int numSize = numbers.size();
    for (int i = numSize - 1; i >= 0; i--) {
        cout << numbers[i];
    }
    return 0;
}