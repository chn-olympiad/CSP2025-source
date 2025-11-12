#include<bits/stdc++.h>
#define mkp make_pair
using namespace std;
constexpr long long N=1e4+1e2,M=1e6,V=1e18;
long long n,m,k;
struct 
{
	int to,nxt;
	long long w;
}edge[5*M+5];
int head[N+5],cnt;
void ad(int u,int v,long long w)
{
	edge[++cnt]={v,head[u],w};
	head[u]=cnt;
}
long long w[N+5];
long long prim(unordered_set<int> st)
{
	using pr=pair<long long,int>;
	priority_queue<pr,
	vector<pr>,greater<pr>> q;
	long long ret=0;
	st.erase(1);
	for(int i=head[1];i;i=edge[i].nxt)
	{
		const int& to=edge[i].to;
		const long long& w=edge[i].w;
		if(st.count(to)) q.push(mkp(w,to));
	}
	for(;!st.empty();)
	{
		auto t=q.top();q.pop();
		if(!st.count(t.second)) continue;
		st.erase(t.second);ret+=t.first;
		for(int i=head[t.second];i;i=edge[i].nxt)
		{
			const int& to=edge[i].to;
			const long long& w=edge[i].w;
			if(st.count(to)) q.push(mkp(w,to));
		}
	}
	return ret;
}
unordered_set<int> stk;
long long ans=LONG_LONG_MAX,dxw=0;
void dfs(int nw,long long sum)
{
	if(nw==k+1)
	{
//		cout<<++dxw<<"\n";
		ans=min(ans,prim(stk)+sum);
		return;
	}
	dfs(nw+1,sum);
	stk.insert(nw+n);
	dfs(nw+1,sum+w[nw]);
	stk.erase(nw+n);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		long long w;
		cin>>u>>v>>w;
		ad(u,v,w);ad(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>w[i];
		for(int j=1;j<=n;j++)
		{
			long long x;
			cin>>x;
			ad(j,n+i,x);
			ad(n+i,j,x);
		}
	}
	stk.reserve(N);
	for(int i=1;i<=n;i++) stk.insert(i);
	dfs(1,0);
	cout<<ans;
	return 0;
}
//O(m2^klog n)
//
