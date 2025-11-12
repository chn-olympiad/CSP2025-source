#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
const long long mod = 998244353;
int a[N],n,flag;
long long ans;
bool vis[N];
int read()
{
    int f=1,x=0;
    char c = getchar();
    while(!isdigit(c))
        f = c == '-' ? -1 : 1,c = getchar();
    while(isdigit(c))
        x = (x << 3) + (x << 1) + ( c ^ 48),c = getchar();
    return f*x;
}
void dfs(int len,int maxn,int sum,int dep,int now)
{
    if(dep == len && sum > 2*maxn)
    {
        ans++;
        return;
    }
    for(int i=now+1;i<=n;i++)
    {
        dfs(len,max(maxn,a[i]),sum+a[i],dep+1,i);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n = read();
    for(int i=1;i<=n;i++)
    {
        a[i] = read();
        if(a[i]!=1) flag = 1;
    }
    if(flag)
    {
        for(int len = 3;len <= n;len++)
                dfs(len,0,0,0,0);
            printf("%lld\n",ans % mod);
    }
    else
    {
        for(int i=3;i<=n;i++)
        {
            long long cnt=1;
            for(int j=n;j>=n-i+1;j--)
            {
                cnt = cnt * j / (n - j + 1);
            }
            ans = (ans + cnt) % mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}