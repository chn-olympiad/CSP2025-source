#include <bits/stdc++.h>
using namespace std;
#define int long long

string s, t;

signed main(){
    freopen("number.in", "r", stdin); freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s; for (auto i: s) if (isdigit(i)) t.push_back(i); sort(t.begin(), t.end(), greater<>()); cout << t;

    return 0;
}