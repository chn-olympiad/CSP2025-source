#include<bits/stdc++.h>
using namespace std;
struct edge
{
	long long int u,v,w;
	bool operator<(const edge &x)const{
	return w<x.w;
	}
};
long long int n,m,k,e[11][10001],ans=1e18;
int f[20000],cnt;
int find(int p)
{
	if(p==f[p]) return p;
	return f[p]=find(f[p]);
}
vector<edge> q;
long long int solve()
{
	for(int i=1;i<=n+k;i++) f[i]=i;
	vector<edge> t;
	long long int res=0;
	for(int i=0;i<q.size();i++)
	{
		if(t.size()==cnt) break;
		edge x=q[i];
		if(find(x.u)==find(x.v)) continue;
		t.push_back(x);res+=x.w;
		f[f[x.v]]=f[x.u];
	}
	q=t;
	return res;
}
void dfs(int p,long long int now)
{
	if(p==k+1)
	{
		if(ans>now) ans=now;
		return;
	}
	dfs(p+1,now);
	vector<edge> g=q;
	for(int i=1;i<=n;i++) q.push_back((edge){i,n+p,e[p][i]});
	sort(q.begin(),q.end());
	cnt++;
	now=solve();
	dfs(p+1,e[p][0]+now);
	cnt--;
	q=g;
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++) cin>>u>>v>>w,q.push_back((edge){u,v,w});
	for(int i=1;i<=k;i++) for(int j=0;j<=n;j++) cin>>e[i][j];
	sort(q.begin(),q.end());
	cnt=n-1,ans=solve();
	dfs(1,ans);
	cout<<ans;
}
