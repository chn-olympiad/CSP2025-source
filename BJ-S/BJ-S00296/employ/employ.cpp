#include <bits/stdc++.h>
using namespace std;
const long long Mod = 998244353;

long long n, cn, m, s[600], ans;
vector<long long> c;
string str;
bool A = 1, M1 = 0;

long long Q(long long x)
{
    long long res = 1;
    while(x > 0)
    {
        res = (res * x) % Mod;
        x--;
    }
    return res % Mod;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> str;
    cn = n;
    if(m == 1)
        M1 = 1, A = 0;
    c.push_back(0);
    for(int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if(c[i] != 0)
        {
            c.push_back(t);
            cn--;
        }
        s[i] = str[i - 1] - '0';
        if(s[i] == 0)
            A = 0;
    }

    if(M1 == 1)
    {
        if(s[1] == 1)
        {
            ans = cn * Q(n - 1) % Mod;
        }
    }
    else if(A == 1)
    {
        ans = Q(m);
    }
    else
    {

    }

    cout << ans << "\n";

    return 0;
}
