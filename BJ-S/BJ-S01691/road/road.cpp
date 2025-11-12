#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll inf=1e18;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll n,m,k;
struct E
{
    ll u,v,w;
}e[1000005];
bool operator < (E x,E y){return x.w<y.w;}
bool operator > (const E x,const E y){return x.w>y.w;}
E re[20005];ll cntr;
ll fr[20005];
ll find(ll x){return fr[x]=(fr[x]==x?x:find(fr[x]));}
vector<E> ex[15];
ll c[15];
priority_queue<E,vector<E>,greater<E> >q;
ll tp[15];
ll calc(ll realk)
{
    for(int i=1;i<=k;i++)tp[i]=0;tp[0]=1;
    ll res=0;
    ll cnt=n+realk;
    while(!q.empty())
    {
        E x=q.top();q.pop();
        ll id=0;
        if(x.u>n)id=x.u-n;
        if(id==0&&tp[id]!=n-1)tp[id]++,q.push(re[tp[id]]);
        if(id>0&&tp[id]!=n-1)tp[id]++,q.push(ex[id][tp[id]]);
        ll u=x.u,v=x.v,w=x.w;
        if(find(u)!=find(v))fr[find(u)]=find(v),res+=w,cnt--;
        if(cnt==1)while(!q.empty())q.pop();
    }
    return res;
}
void solve()
{
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++)e[i].u=read(),e[i].v=read(),e[i].w=read();
    for(int i=1;i<=k;i++)
    {
        c[i]=read();
        for(int j=1;j<=n;j++)
        {
            ll x=read();
            ex[i].push_back({n+i,j,x});
        }
        sort(ex[i].begin(),ex[i].end());
    }
    sort(e+1,e+m+1);
    for(int i=1;i<=n;i++)fr[i]=i;
    for(int i=1;i<=m;i++)
    {
        ll u=e[i].u,v=e[i].v,w=e[i].w;
        if(find(u)!=find(v))fr[find(u)]=find(v),re[++cntr]=e[i];
    }
    ll ans=inf;
    for(int S=0;S<(1<<k);S++)
    {
        while(!q.empty())q.pop();
        for(int i=1;i<=n+k;i++)fr[i]=i;
        q.push(re[1]);
        ll res=0,cnt=0;
        for(int i=1;i<=k;i++)
        {
            if(S&(1<<(i-1)))
            {
                res+=c[i];
                q.push(ex[i][0]);
                cnt++;
            }
        }
        res+=calc(cnt);
        ans=min(ans,res);
    }
    cout<<ans<<'\n';
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    // clock_t start=clock();
    ll c=0,t=1;
    while(t--)solve();
    // clock_t end=clock();
    // cerr<<(end-start)*1.00/CLOCKS_PER_SEC<<'\n';
    return 0;
}