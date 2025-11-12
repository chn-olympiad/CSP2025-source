#include <bits/stdc++.h>
using namespace std;
#define INF 998244353
int a[5005],s[5005];
long long f[505][50005];
int dfs(int mxp,int p,int sum)
{
    if (s[p]+sum<=a[mxp]) return 0;
    if (p==0) return sum>a[mxp];
    if (f[p][sum]==-1) f[p][sum]=(dfs(mxp,p-1,sum+a[p])%INF+dfs(mxp,p-1,sum)%INF)%INF;
    return f[p][sum];
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,s_=0;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort (a+1,a+n+1);
    for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    long long ans=0;
    for (int i=3;i<=n;i++)
    {
        memset(f,-1,sizeof(f));
        ans+=dfs(i,i-1,0);
        ans%=INF;
    }
    cout << ans;
    return 0;
}
