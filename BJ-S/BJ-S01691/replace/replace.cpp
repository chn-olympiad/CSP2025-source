#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<ctime>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll inf=1e18;
const ll mod=1234567891;
const ll mod1=998244353;
const ll base=251;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline char gtc()
{
    char ch=getchar();
    while(ch!='0'&&ch!='1')ch=getchar();
    return ch;
}
ll n,Q;
int trie[3000005][26],cntr,fat[3000005];
ll rtl[200005],rtr[200005];
int lpos[3000005],rpos[3000005],f[3000005];
vector<int> vec[3000005],q[3000005];
ll ans[200005];
string s[2],t[2];
map<ll,ll> mp;
bool vis[3000005];
void dfs(ll u)
{
    vis[u]=1;
    for(auto x:vec[u])f[x]++;
    for(auto x:q[u])
    {
        ll res=0,p=rpos[x];
        while(p)res+=f[p],p=fat[p];
        ans[x]=res;
    }
    for(int i=0;i<26;i++)
    {
        if(trie[u][i])dfs(trie[u][i]);
    }
    for(auto x:vec[u])f[x]--;
}
void solve()
{
    cin>>n>>Q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[0]>>s[1];
        ll m=s[0].length();
        ll l=0,r=m-1;
        while(l<m&&s[0][l]==s[1][l])l++;
        while(r>=0&&s[0][r]==s[1][r])r--;
        if(l>r)continue;
        ll hs=0,hs1=0;
        for(int j=l;j<=r;j++)
        {
            hs=hs*base+s[0][j],hs%=mod;
            hs=hs*base+s[1][j],hs%=mod;
            hs1=hs1*base+s[0][j],hs1%=mod1;
            hs1=hs1*base+s[1][j],hs1%=mod1;
        }
        hs=hs+hs1*mod;
        if(!mp[hs])mp[hs]=(++cntr),cntr++;
        rtl[i]=mp[hs],rtr[i]=rtl[i]+1;
        ll rt=rtl[i];
        for(int j=l-1;j>=0;j--)
        {
            if(!trie[rt][s[0][j]-'a'])trie[rt][s[0][j]-'a']=(++cntr),fat[cntr]=rt;
            rt=trie[rt][s[0][j]-'a'];
        }
        ll prt=rt;
        rt=rtr[i];
        for(int j=r+1;j<m;j++)
        {
            if(!trie[rt][s[0][j]-'a'])trie[rt][s[0][j]-'a']=(++cntr),fat[cntr]=rt;
            rt=trie[rt][s[0][j]-'a'];
        }
        vec[prt].push_back(rt);
        // cout<<"qwq "<<prt<<' '<<rt<<'\n';
    }
    // for(int i=1;i<=cntr;i++)cout<<fat[i]<<' ';cout<<'\n';
    for(int i=1;i<=Q;i++)
    {
        cin>>t[0]>>t[1];
        if(t[0].length()!=t[1].length())continue;
        ll m=t[0].length();
        ll l=0,r=m-1;
        while(l<m&&t[0][l]==t[1][l])l++;
        while(r>=0&&t[0][r]==t[1][r])r--;
        ll hs=0,hs1=0;
        for(int j=l;j<=r;j++)
        {
            hs=hs*base+t[0][j],hs%=mod;
            hs=hs*base+t[1][j],hs%=mod;
            hs1=hs1*base+t[0][j],hs1%=mod1;
            hs1=hs1*base+t[1][j],hs1%=mod1;
        }
        hs=hs+hs1*mod;
        // if(i==1658)cerr<<"qwq "<<mp[hs]<<'\n';
        if(!mp[hs])continue;
        ll rt=mp[hs];
        for(int j=l-1;j>=0;j--)
        {
            if(!trie[rt][t[0][j]-'a'])break;
            rt=trie[rt][t[0][j]-'a'];
        }
        q[rt].push_back(i);lpos[i]=rt;
        rt=mp[hs]+1;
        for(int j=r+1;j<m;j++)
        {
            if(!trie[rt][t[0][j]-'a'])break;
            rt=trie[rt][t[0][j]-'a'];
        }
        rpos[i]=rt;
    }
    for(int i=1;i<=cntr;i++)
    {
        if(vis[i])continue;
        dfs(i);
    }
    for(int i=1;i<=Q;i++)cout<<ans[i]<<'\n';
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    // clock_t start=clock();
    ll c=0,t=1;
    while(t--)solve();
    // clock_t end=clock();
    // cerr<<(end-start)*1.00/CLOCKS_PER_SEC<<'\n';
    return 0;
}