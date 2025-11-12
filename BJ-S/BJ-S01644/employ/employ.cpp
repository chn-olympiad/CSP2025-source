#include <bits/stdc++.h>
using namespace std;
long long n, m, p[10005];
string s;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for(int i = 0;i < n;i ++)
    {
        cin >> p[i];
    }
    long long an = 1, mod = 998244353;
    for(int i = n;i >= 2;i --) an = (an * i) % mod;
    cout << an;
    return 0;
}
