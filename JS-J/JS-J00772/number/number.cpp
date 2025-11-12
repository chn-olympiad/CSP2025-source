#include <bits/stdc++.h>
#define int long long
#define rg register
using namespace std;
const int MAXN = 1000000 + 5;
string s1;
int a[MAXN];
inline void fre()
{
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);
    return ;
}
signed main()
{
    fre();
    cin >> s1;
    for (rg int i = 0; i < s1.size(); i++)
    {
        if (!isdigit(s1[i])) continue;
        a[s1[i] - '0']++;
    }
    for (rg int i = 9; i >= 0; i--){
        for (rg int j = 1; j <= a[i]; j++)
        {
            printf ("%lld", i);
        }
    }
    return 0;
}

