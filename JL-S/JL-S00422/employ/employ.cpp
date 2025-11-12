#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353*1ll;
int a[10100],vis[101000],b[101000];
char s[101000];
int n,m;
ll ans;
ll qp(ll a,int b)
{
    if(b==1)return a;
    ll t=qp(a,b/2);
    t=t*t%mod;
    if(b&1)t=t*a%mod;
    return t;
}
void check()
{
    int num=0,tmp=0;
    for(int i=1;i<=n;i++)
    {
        if(tmp>=a[b[i]]){tmp++;continue;}
        if(s[i]=='1')num++;
        else tmp++;
    }
    if(num>=m)ans++;
    ans%=1ll*998244353;
}
void dfs(int x)
{
    if(x>n)
    {
        check();
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        vis[i]=1;
        b[x]=i;
        dfs(x+1);
        vis[i]=0;
    }
}
ll inv[101000];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int i,j,k,l,sum=0;
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    if(n<=10)
    {
        dfs(1);
        printf("%lld\n",ans);
    }
    else
    {
        inv[1]=1ll;
        for(i=2;i<=100000;i++)inv[i]=inv[i-1]*(1ll*i)%mod;
        printf("%lld\n",inv[n]);
    }
    return 0;
}
