#include <bits/stdc++.h>
using namespace std;

const int P = 998244353, NR = 510;
int n, m, s[NR], cnt0[NR], c[NR];

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    int flagA = 1;
    for(int i = 1; i <= n; i++)
    {
        char ts;
        cin >> ts;
        s[i] = ts - '0';
        cnt0[i] = cnt0[i - 1] + (s[i] ^ 1);
        flagA &= s[i];
    }
    int cfA = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
        if(!c[i]) cfA++;
    }
    if(cfA > n - m)
    {
        cout << "0\n";
        return 0;
    } 
    if(flagA)
    {
        int tres = 1;
        for(int i = 2; i <= n; i++)
        {
            tres = 1ll * tres * i % P;
        }
        cout << tres << '\n';
        return 0;
    }
    return 0;
}