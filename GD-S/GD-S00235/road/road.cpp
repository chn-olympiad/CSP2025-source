#include<bits/stdc++.h>
using namespace std;
struct f{
	long long num;
	long long id;
};
long long cmp(f x,f y)
{
	if(x.num!=y.num) return x.num<y.num;
	else return x.id<y.id; 
}
struct asd{
	vector<long long> to;
	vector<long long> len;
	void clear()
	{
		f cnt[to.size()+3];
		long long l=0;
		for(long long i=0;i<to.size();i++)
			cnt[++l].num=len[i],cnt[l].id=to[i];
		sort(cnt+1,cnt+1+to.size(),cmp);
		for(long long i=0;i<to.size();i++)
			len[i]=cnt[i+1].num,to[i]=cnt[i+1].id;
	}
}a[10401];
struct data{
	asd Son;
	long long father;
	long long len_to_first;
}tree[10401];
long long n,m,maxn;
void link(long long x,long long y,long long w)
{
	a[x].to.push_back(y);
	a[y].to.push_back(x);
	a[x].len.push_back(w);
	a[y].len.push_back(w);
}
bool vis[10401];
void dfs(long long k,long long fa)
{
	vis[k]=true;
	for(long long i=0;i<a[k].to.size();i++)
	{
		long long v=a[k].to[i],d=a[k].len[i];
		if(vis[v]||v==fa) continue;
		tree[v].father=k;
		tree[k].Son.to.push_back(v);
		tree[k].Son.len.push_back(d);
		dfs(v,k);
	}
}
void DFS(long long k)
{
	for(long long i=0;i<tree[k].Son.to.size();i++)
	{
		long long v=tree[k].Son.to[i];
		tree[v].len_to_first=tree[k].len_to_first+tree[k].Son.len[i];
		maxn+=tree[k].Son.len[i];
		DFS(v);
	}
}
struct y{
	asd G;
	long long build_pay;
}g[41];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long k;
	cin>>n>>m>>k;
	for(long long i=1,x,y,w;i<=m;i++) cin>>x>>y>>w,link(x,y,w);
	for(long long i=1;i<=n;i++) a[i].clear(),vis[i]=false;
	dfs(1,0),tree[1].len_to_first=tree[1].father=0;
	DFS(1);
	for(long long i=1;i<=k;i++)
	{
		cin>>g[i].build_pay;
		for(long long j=1,d;j<=n;j++)
			cin>>d,g[i].G.to.push_back(j),g[i].G.len.push_back(d);
	}
	bool flag=true;
	for(long long i=1;i<=k;i++) g[i].G.clear();
	for(long long i=1;i<=k;i++) flag=(flag&&g[i].G.len[g[i].G.to.size()-1]==0&&g[i].build_pay==0);
	if(k==0) cout<<maxn;
	else if(flag) cout<<0;
	else
	{
		for(long long i=1;i<=k;i++)
		{
			long long ans=0,s=0,t=0;
			for(long long j=1;j<=n;j++)
				for(long long l=j+1;l<=n;l++)
					if(ans<abs(tree[j].len_to_first-tree[l].len_to_first))
						s=j,t=l,ans=abs(tree[j].len_to_first-tree[l].len_to_first);
			if(ans<ans+g[i].build_pay-min(tree[s].Son.len[tree[s].Son.len.size()-1],tree[t].Son.len[tree[t].Son.len.size()-1])) continue;
			n++;
			tree[s].father=n;
			tree[n].Son.to.push_back(s);
			tree[n].Son.len.push_back(g[i].G.len[s-1]);
			tree[t].Son.to.push_back(n);
			tree[n].father=t;
			tree[t].Son.to.push_back(n);
			tree[t].Son.len.push_back(g[i].G.len[t-1]);
			tree[t].Son.to.push_back(t);
			tree[s].Son.clear();
			tree[t].Son.clear();
			tree[n].Son.clear();
			maxn=g[i].build_pay,DFS(1);
		}
	}
	return 0;
}
