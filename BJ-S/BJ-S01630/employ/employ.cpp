#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500 + 5;
const int mod = 998244353;
int n, m, a[N], x[N];
bool flag[N];
signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        flag[i] = ch - '0';
    }
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(n <= 10)
    {
        for(int i = 1; i <= n; i++) x[i] = i;
        int ans = 0;
        do
        {
            int cnt = 0;
            for(int i = 1; i <= n; i++)
            {
                if(!flag[i] || cnt >= a[x[i]])
                    cnt++;
            }
            if(n - cnt >= m)
                ans++;
        }
        while(next_permutation(x + 1, x + n + 1));
        cout << ans <<endl;
    }
    else
        cout << 0 <<endl;
    return 0;
}
