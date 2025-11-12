#include<bits/stdc++.h>
#define ll int
using namespace std;
ll n,q;
struct ACAM
{
	struct px
	{
		ll son[26],fail,dep;
	}tr[2500005];
	#define son(x,a) tr[x].son[a]
	#define f(x) tr[x].fail
	#define d(x) tr[x].dep
	ll cot;
	ll insert(string &s)
	{
		ll now=0;
		for(ll i=0;i<s.size();++i)
		{
			if(!son(now,s[i]-'a'))son(now,s[i]-'a')=++cot,d(cot)=d(now)+1;
			now=son(now,s[i]-'a');
		}
		return now;
	}
	void bfs()
	{
		queue<ll>q;
		for(ll i=0;i<26;++i)
			if(tr[0].son[i])q.emplace(tr[0].son[i]);
		while(!q.empty())
		{
			ll id=q.front();q.pop();
			for(ll i=0;i<26;++i)
				if(tr[id].son[i])
				{
					f(son(id,i))=son(f(id),i);
					q.emplace(son(id,i));
				}
				else tr[id].son[i]=tr[f(id)].son[i];
		}
	}
}a[2];
ll tot,dfn[2500005],sz[2500005];
struct BIT
{
	ll tr[2500005];
	ll lowbit(ll x)
	{
		return x&(-x);
	}
	void upd(ll x,ll val)
	{
		for(ll i=x;i<=tot;i+=lowbit(i))tr[i]+=val;
	}
	ll query(ll x)
	{
		ll res=0;
		for(ll i=x;i;i-=lowbit(i))res+=tr[i];
		return res;
	}
}s;
vector<ll>w[2500005];
struct xp
{
	ll u,uid,av;
};
vector<xp>ask[2500005];
long long res[200005];
ll head[2500005],cnt;
struct ed
{
	ll v,next;
}edge[2500005];
void add(ll u,ll v)
{
	edge[++cnt].v=v;edge[cnt].next=head[u];head[u]=cnt;
}
void dsf(ll id)
{
	dfn[id]=++tot;sz[id]=1;
	for(ll i=head[id];i;i=edge[i].next)
	dsf(edge[i].v),sz[id]+=sz[edge[i].v];
}
ll f[2500005],dep[2500005],lf[2500005];
void dfs(ll id)
{
	dep[id]=dep[f[id]]+1;
	lf[id]=((dep[f[id]]-dep[lf[f[id]]]!=dep[lf[f[id]]]-dep[lf[lf[f[id]]]])?f[id]:lf[lf[f[id]]]);
	for(ll i=head[id];i;i=edge[i].next)
	f[edge[i].v]=id,dfs(edge[i].v);
}
void done(ll id)
{
	for(auto it:w[id])s.upd(dfn[it],1),s.upd(dfn[it]+sz[it],-1);
	for(auto it:ask[id]) 
	res[it.uid]+=it.av*s.query(dfn[it.u]);
	for(ll i=head[id];i;i=edge[i].next)
	done(edge[i].v);
	for(auto it:w[id])s.upd(dfn[it],-1),s.upd(dfn[it]+sz[it],1);
}
int main()
{
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	string s[2];
	for(ll i=1;i<=n;++i)
	{
		ll where[2];
		for(ll j=0;j<2;++j)
		cin>>s[j],where[j]=a[j].insert(s[j]);
		w[where[0]].emplace_back(where[1]);
	}
	for(ll i=1;i<=tot;++i)sort(w[i].begin(),w[i].end());
	a[0].bfs();
	a[1].bfs();
	string t[2];
	for(ll i=1;i<=a[1].cot;++i)add(a[1].f(i),i);
	dsf(0);
	for(ll i=0;i<=a[1].cot;++i)head[i]=0;
	cnt=0;
	for(ll i=1;i<=a[0].cot;++i)add(a[0].f(i),i);
	dfs(0);
	for(ll sb=1;sb<=q;++sb)
	{
		ll sp=0,st=0;
		ll where[2]={0,0};
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size())
		continue;
		ll l=t[0].size();
		t[0]=" "+t[0];
		t[1]=" "+t[1];
		for(ll i=1;i<=l;++i)
		{
			if(t[0][i]!=t[1][i])break;
			++sp;
		}
		for(ll i=l;i;--i)
		{
			if(t[0][i]!=t[1][i])break;
			++st;
		}
		for(ll i=1;i<=l;++i)
		{
			for(ll j=0;j<2;++j)
			{
				while(where[j]&&!a[j].son(where[j],t[j][i]-'a'))where[j]=a[j].f(where[j]);
				where[j]=a[j].son(where[j],t[j][i]-'a');
			}
			if(l-i>st)continue;
			ll ml=max(0,i-sp);
			if(a[0].d(where[0])<ml)continue;
			ask[where[0]].emplace_back((xp){where[1],sb,1});
			if(ml)
			{
				ll u=where[0];
				while(a[0].d(f[u])>=ml)
				{
					if(a[0].d(lf[u])>=ml)u=lf[u];
					else u=f[u];
				}
				u=f[u];
				ask[u].emplace_back((xp){where[1],sb,-1});
			}
		}
	}
	done(0);
	for(ll i=1;i<=q;++i)cout<<res[i]<<'\n';
}//考虑对 s 建立 AC 机
//有一个 L2\log 的做法 
//这个做法太变态了
//狂野，震撼《》
//为自由美好永不放弃！ 