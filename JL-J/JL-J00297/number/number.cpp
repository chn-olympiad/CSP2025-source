#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    string num;
    vector<int> vc;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            vc.push_back(s[i] - '0');
        }
    }
    sort(vc.begin(), vc.end());
    reverse(vc.begin(), vc.end());
    for (int i = 0; i < vc.size(); i++) {
        cout << vc[i];
    }
    return 0;
}
