#include<bits/stdc++.h>
using namespace std;
const long long N = 5010;
long long a[N];
const long long mod = 998244353;
long long n;
long long k;
long long res = 0;
long long ans[N];
const int M = 510;
//long long sum[M][M];
//long long mxl[M][M];
void dfs(long long cnt,long long now)
{
    if(now == n + 1)
    {
        if(cnt == k)
        {
            long long tmp = 0;
            long long mx = -1;
            for(long long i = 0;i < k;i++)
            {
                 tmp += a[ans[i]];
                 if(mx < a[ans[i]])
                 {
                     mx = a[ans[i]];
                 }
            }
            if(tmp > 2 * mx)
            {
                res = (res + 1) % mod;
            }
        }
    }
    else
    {
        ans[cnt] = now;
        dfs(cnt + 1,now + 1);
        dfs(cnt,now + 1);
    }
}
long long C(long long a,long long b)
{
    if(a == b)
    {
        return 1;
    }
    long long tmp = 1;
    for(long long i = 1;i <= a;i++)
    {
        tmp = (tmp * i) % mod;
    }
    long long tmp2 = 1;
    for(long long i = 1;i <= b;i++)
    {
        tmp2 = (tmp2 * i) % mod;
    }
    long long tmp3 = 1;
    for(long long i = 1;i <= a - b;i++)
    {
        tmp3 = (tmp3 * i) % mod;
    }
    long long tmpz = 0;
    for(long long i = 1;i <= tmp3;i++)
    {
        tmpz = (tmpz + tmp2) % mod;
    }
    return tmp / tmpz;
}
void solve1()
{
    long long ret = 0;
    for(long long i = 4;i <= n;i++)
    {
        ret = (ret + C(n,i) % mod) % mod;
    }
    printf("%lld",ret);
}
void solve2()
{
    for(long long i = 3;i <= n;i++)
    {
        k = i;
        dfs(0,1);
    }
    printf("%lld",res);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    bool flag = true;
    for(long long i = 1;i <= n;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i] != 1)
        {
            flag = false;
        }
    }
    if(flag == true)
    {
        solve1();
    }
    else if(n <= 20)
    {
        solve2();
    }
    else if(n <= 500)
    {

    }
    return 0;
}
