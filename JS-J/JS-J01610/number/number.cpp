#include <bits/stdc++.h>
using namespace std;
string str;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin.tie(0);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> str;
    vector<int> vec;
    for (auto ch : str) {
        if (isdigit(ch)) {
            vec.push_back(ch - '0');
        }
    }
    sort(vec.begin(), vec.end(), [](int a, int b) {
        return a > b;
     });
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
    }
    cout << '\n';
    return 0;
}
