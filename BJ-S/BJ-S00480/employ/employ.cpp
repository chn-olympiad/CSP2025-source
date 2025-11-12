#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    bool f = 1;
    for(int i = 0;i < s.size();i++)
        if(s[i] != '1')
            f = 0;
    cout << rand() % 998244353;
    return 0;
}
