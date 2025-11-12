#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string s;
vector<string> num;

bool cmp(string a, string b) {
    return a >= b;
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if ('0' <= s[i] && s[i] <= '9')
            num.push_back({s[i]});
    sort(num.begin(), num.end(), cmp);
    for (auto& n : num) cout << n;

    return 0;
}
