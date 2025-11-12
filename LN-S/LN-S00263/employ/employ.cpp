#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=505;
const int p=998244353;
int n,m,c[N];char s[N];
void upd(ll &x,ll y)
{if((x+=y)>=p)x-=p;}
namespace sub1{
ll f[1<<18][19],ct[1<<18];
void solve()
{
    f[0][0]=1;
    for(int s=0;s<(1<<n);s++)
    {
        if(s){ct[s]=ct[s^(s&-s)]+1;}
        int d=ct[s];for(int i=0;i<=d;i++)
        {
            if(!f[s][i])continue;
            for(int j=1;j<=n;j++)
            {
                if(s&(1<<j-1))continue;
                upd(f[s^(1<<j-1)][i+(::s[d+1]=='0'||c[j]<=i)],f[s][i]);
            }
        }
    }int S=(1<<n)-1;ll ans=0;
    for(int i=0;i<=n-m;i++)
    upd(ans,f[S][i]);cout<<ans<<'\n';
}
}
namespace sub2{
int ps[N],t[N];
void solve()
{
    sort(c+1,c+n+1);
    ps[0]=1;while(ps[0]<n&&c[ps[0]+1]<=0)ps[0]++;
    for(int i=1;i<=n;i++)
    {
        ps[i]=ps[i-1];
        while(ps[i]<n&&c[ps[i]+1]<=i)ps[i]++;
    }ll ans=1;for(int i=1;i<=n;i++)ans=ans*i%p;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0')t[i]=n;
        else t[i]=ps[i-1];
    }sort(t+1,t+n+1);ll vl=1;
    for(int i=1;i<=n;i++)
    vl=vl*(t[i]-i+1)%p;
    cout<<(ans+p-vl)%p<<'\n';
}
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>s+1;
    for(int i=1;i<=n;i++)cin>>c[i];
    if(n<=18)return sub1::solve(),0;
    if(m==1)return sub2::solve(),0;
    if(m==n)
    {
        for(int i=1;i<=n;i++)
        if(s[i]=='0')return cout<<"0\n",0;
        for(int i=1;i<=n;i++)
        if(c[i]=='0')return cout<<"0\n",0;
        ll ans=1;for(int i=1;i<=n;i++)
        ans=ans*i%p;cout<<ans<<'\n';return 0;
    }
    return 0;
}
