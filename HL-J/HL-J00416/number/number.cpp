#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    vector<int> v;
    for(int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) v.push_back(s[i] - '0');
    }
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; i--) cout << v[i];
    cout << endl;
    fclose(stdin), fclose(stdout);
    return 0;
}
