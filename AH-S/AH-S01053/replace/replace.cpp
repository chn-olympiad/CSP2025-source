#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N=5000005,M=200005;
constexpr ll mod=998244853;
char s[N],t[N];
int tr[N][26],dfn[N],ed[N],rt[M],L[M],R[M],ans[M],n,q,nd,k,tt;
vector<int>e[N],bl[N];
map<ll,int>mp,mp2;
ll get(const int l,const int r)
{
	ll S=0;
	for(int i=l;i<=r;++i)
		S=(S*26+s[i]-'a')%mod,S=(S*26+t[i]-'a')%mod;
	return S;
}
int insert(int u,const int l,const int r,const int d=-1)
{
	for(int i=l;i<=r;++i)
	{
		if(!tr[u][s[i]-'a'])
			tr[u][s[i]-'a']=++nd;
		u=tr[u][s[i]-'a'];
	}
	if(~d)
		bl[u].push_back(d);
	return u;
}
int fd(int u,const int l,const int r)
{
	for(int i=l;i<=r;++i)
	{
		if(!tr[u][s[i]-'a'])
			break;
		u=tr[u][s[i]-'a'];
	}
	return u;
}
void input()
{
	cin>>s+1>>t+1;
	int n=strlen(s+1);
	int l=n+1,r=0;
	for(int i=1;i<=n;++i)
		if(s[i]!=t[i])
			l=min(l,i),r=max(r,i);
	if(!r)
		return;
	ll h=get(l,r);
	if(!mp.count(h))
		mp[h]=++k,rt[k]=++nd,++nd;
	reverse(s+1,s+l);
	int u=insert(rt[mp[h]]+1,r+1,n);
	insert(rt[mp[h]],1,l-1,u);
}
void input2(const int i)
{
	cin>>s+1>>t+1;
	int n=strlen(s+1);
	int l=n+1,r=0;
	for(int i=1;i<=n;++i)
		if(s[i]!=t[i])
			l=min(l,i),r=max(r,i);
	ll h=get(l,r);
	if(!mp.count(h))
		return;
	reverse(s+1,s+l);
	L[i]=fd(rt[mp[h]],1,l-1),R[i]=fd(rt[mp[h]]+1,r+1,n);
	//cout<<L[i]<<' '<<R[i]<<'\n';
	e[L[i]].push_back(i);
}
namespace BIT{
	int v[N];
	inline int lowbit(const int x)
	{
		return x&(-x);
	}
	inline void add(int x,const int d)
	{
		for(;x<=tt;x+=lowbit(x))
			v[x]+=d;
	}
	inline int query(int x)
	{
		int s=0;
		for(;x;x-=lowbit(x))
			s+=v[x];
		return s;
	}
}
void dfs(const int k)
{
	dfn[k]=++tt;
	for(int i=0;i<26;++i)
		if(tr[k][i])
			dfs(tr[k][i]);
	ed[k]=tt;
}
void dfs2(const int k)
{
	for(int i:bl[k])
		BIT::add(dfn[i],1),BIT::add(ed[i]+1,-1);//,cout<<dfn[i]<<'\n';
	for(int i:e[k])
		ans[i]+=BIT::query(dfn[R[i]]);//,cout<<"*"<<dfn[R[i]]<<'\n';
	for(int i=0;i<26;++i)
		if(tr[k][i])
			dfs2(tr[k][i]);
	for(int i:bl[k])
		BIT::add(dfn[i],-1),BIT::add(ed[i]+1,1);
}
void solve(const int ttt)
{
	tt=0,dfs(rt[ttt]+1),dfs2(rt[ttt]);
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
		input();
	for(int i=1;i<=q;++i)
		input2(i);
	for(int i=1;i<=k;++i)
		solve(i);
	for(int i=1;i<=q;++i)
		cout<<ans[i]<<'\n';
	return 0;
}
