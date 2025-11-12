#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,ans;
struct stt
{
    ll a,b,c;
}p[100010];
void dfs(ll now,ll ac,ll bc,ll cc,ll sum)
{
    if(ac+bc+cc==n)
    {
        if(ac<=n/2&&bc<=n/2&&cc<=n/2)
            ans=max(ans,sum);
        return;
    }
    dfs(now+1,ac+1,bc,cc,sum+p[now+1].a);
    dfs(now+1,ac,bc+1,cc,sum+p[now+1].b);
    dfs(now+1,ac,bc,cc+1,sum+p[now+1].c);
    return;
}
bool cmp(stt x,stt y)
{
    if(x.a==y.a)
        return a.b<a.b;
    return x.a>y.a;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    bool fl=1;
    while(t--)
    {
        ans=0;
        cin>>n;
        if(n<=15)
        {
            for(ll i=1;i<=n;i++)
                cin>>p[i].a>>p[i].b>>p[i].c;
            dfs(0,0,0,0,0);
            cout<<ans<<'\n';
            continue;
        }
        for(ll i=1;i<=n;i++)
        {
            cin>>p[i].a>>p[i].b>>p[i].c;
            if(p[i].a!=0)fl=0;
        }
        if(fl)
        {
            sort(p+1,p+n+1,cmp);
            for(ll i=1;i<=n/2;i++)
                ans+=p[i].a;
            cout<<ans<<'\n';
            continue;
        }
        
    }
    return 0;
}
