#include <bits/stdc++.h>
#define ll int
#define pll pair<ll,ll>
#define fs first
#define sc second
#define all(v) v.begin(),v.end()
#define pb push_back
#define ppb pop_back
using namespace std;
const ll N=5e6+5;
ll n,idt,len[N],fail[N],t[N][26];
vector<ll> e[N];
void add(ll x,ll y){e[x].pb(y);}
ll insert(string s)
{
    ll p=0;
    for(auto i:s)
    {
        ll c=i-'a';
        if(!t[p][c])
            len[t[p][c]=++idt]=len[p]+1;
        p=t[p][c];
    }
    return p;
}
void build()
{
    queue<ll> q;
    for(ll i=0;i<26;i++)
        if(t[0][i]) q.push(t[0][i]);
    while(q.size())
    {
        ll x=q.front();
        q.pop();
        for(ll i=0;i<26;i++)
        {
            ll &y=t[x][i];
            if(!y) y=t[fail[x]][i];
            else fail[y]=t[fail[x]][i],q.push(y);
        }
    }
    for(ll i=1;i<=idt;i++)
        add(fail[i],i);
}
ll ts,d[N],to[N],sz[N],dfn[N],son[N],top[N];
void dfs1(ll x)
{
    sz[x]=1;
    for(auto y:e[x])
    {
        d[y]=d[x]+1;
        dfs1(y),sz[x]+=sz[y];
        if(!son[x]||sz[y]>sz[son[x]])
            son[x]=y;
    }
}
void dfs2(ll x,ll tp)
{
    to[dfn[x]=++ts]=x,top[x]=tp;
    if(son[x]) dfs2(son[x],tp);
    for(auto y:e[x])
        if(y^son[x]) dfs2(y,y);
}
ll c[N];
void upd(ll x,ll k)
{
    for(;x<=ts;x+=(x&-x))
        c[x]+=k;
}
ll sum(ll x)
{
    ll ret=0;
    for(;x;x-=(x&-x))
        ret+=c[x];
    return ret;
}
vector<ll> pos[N];
long long ans[N];
string sq[N][2];
ll dfnsum(ll l,ll r){return sum(r)-sum(l-1);}
ll query(ll x,ll y)
{
    ll ret=0;
    while(top[x]^top[y])
    {
        if(d[top[x]]<d[top[y]]) swap(x,y);
        ret+=dfnsum(dfn[top[x]],dfn[x]);
        x=fail[top[x]];
    }
    if(dfn[x]>dfn[y]) swap(x,y);
    ret+=dfnsum(dfn[x],dfn[y]);
    return ret;
}
ll suml(ll p,ll lim)
{
    if(len[p]<lim) return 0;
    ll ret1=0,q=p;ll pp=p;
    while(q&&len[fail[top[q]]]>=lim)
        q=fail[top[q]];
    ll l=dfn[top[q]],r=dfn[q],mid;
    while(l<=r)
    {
        mid=l+r>>1;
        if(len[to[mid]]>=lim)
            q=to[mid],r=mid-1;
        else l=mid+1;
    }
    return query(p,q);
}
struct tmpq{ll x,lim,id;};
vector<tmpq> tq[N];
void dfs3(ll x)
{
    for(auto i:pos[x])
        upd(dfn[i],1);
    for(auto i:tq[x])
        ans[i.id]+=suml(i.x,i.lim);
    for(auto y:e[x])
        dfs3(y);
    for(auto i:pos[x])
        upd(dfn[i],-1);
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll m;cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        pos[insert(s1)].pb(insert(s2));
    }
    for(ll i=1;i<=m;i++)
    {
        cin>>sq[i][0]>>sq[i][1];
        insert(sq[i][0]),insert(sq[i][1]);
    }
    build();
    d[0]=1,dfs1(0),dfs2(0,0);
    for(ll i=1;i<=m;i++)
    {
        string &s1=sq[i][0],&s2=sq[i][1];
        if(s1.size()!=s2.size())
            continue;
        ll sz=s1.size();
        s1=' '+s1,s2=' '+s2;
        ll l=1,r=sz;
        while(s1[l]==s2[l]) l++;
        while(s1[r]==s2[r]) r--;
        ll p1=0,p2=0;
        for(ll j=1;j<r;j++)
            p1=t[p1][s1[j]-'a'],p2=t[p2][s2[j]-'a'];
        for(ll j=r;j<=sz;j++)
        {
            p1=t[p1][s1[j]-'a'],p2=t[p2][s2[j]-'a'];
            tq[p1].pb({p2,j-l+1,i});
        }
    }
    dfs3(0);
    for(ll i=1;i<=m;i++)
        cout<<ans[i]<<'\n';
    return 0;
}