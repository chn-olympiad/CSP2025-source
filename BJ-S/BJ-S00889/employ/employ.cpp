#include<bits/stdc++.h>

using namespace std;
long long n, m;
const int N = 510;
const int mod = 998244353;
char a[N];
long long p[N];
long long ans = 0;
bool num[N];
long long qpow(long long a, long long b)
{
    long long ans = 1;
    for(int i = 1; i <= b; i ++ ) ans *= a;
    return ans;
}
void dfs(long long u, long long cnt)
{
    if(cnt == n + 1)
    {
        long long po = 0;
        long long c = 0;
        for(int i = 1; i <= n; i ++ )
        {
            long long pl = u / qpow(10, i - 1) % 10;
            if(a[i] == '0') po ++ ;
            else
            {
                if(po < p[pl]) c ++;
                else po ++ ;
            }
        }
        if(c >= m)
        {
            ans = (ans + 1) % mod;
        }
        return ;
    }
    for(int i = 1; i <= n; i ++ )
    {
        if(!num[i])
        {
            num[i] = true;
            dfs(u * 10 + i, cnt + 1);
            num[i] = false;
        }
    }
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> a + 1;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> p[i];
    }
    dfs(0ll, 1ll);
    cout << ans << endl;
}
