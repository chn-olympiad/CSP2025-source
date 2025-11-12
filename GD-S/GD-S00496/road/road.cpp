#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using VI=vector<int>;
using PII=pair<int,int>;
#define MP make_pair
#define fi first
#define se second
#define PB emplace_back
#define PPB pop_back
#define endl ('\n')
#define ALL(x) (x).begin(),(x).end()

const int N=10005,M=1e6+5,K=11;
struct E
{
	int u,v,w;
	bool operator<(const E &rhs)const
	{return w<rhs.w;}
}e[M],e2[K][N];
int co[K];
int fa[N+K];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

int n,m,k;

ll ans=1e18;
// int cc=0;

void dfs(int dep,const vector<E> &le,ll lc)
{
	ll cr=lc;
	for(auto [u,v,w]:le)cr+=w;
	// cerr<<dep<<" "<<cr<<endl;
	// if(cr<ans)cc=le.size()-n+1;
	ans=min(ans,cr);

	for(int i=dep+1;i<=k;i++)
	{
		vector<E> ne;
		iota(fa+1,fa+n+k+1,1);
		for(int j=0,l=1;j<le.size()||l<=n;)
		{
			E ce=l>n||j<le.size()&&le[j]<e2[i][l]?le[j++]:e2[i][l++];
			int u=find(ce.u),v=find(ce.v);
			if(u!=v)fa[u]=v,ne.PB(ce);
		}
		// cerr<<dep<<" "<<i<<" "<<ne.size()<<" "<<le.size()<<endl;
		// assert(ne.size()==le.size()+1);
		dfs(i,ne,lc+co[i]);
	}
}

int main()
{
#ifndef LOCAL
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
#endif
	ios::sync_with_stdio(false),cin.tie(nullptr);

	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>co[i];
		for(int j=1;j<=n;j++)cin>>e2[i][j].w,e2[i][j].u=j,e2[i][j].v=n+i;
		sort(e2[i]+1,e2[i]+n+1);
	}
	vector<E> st;
	sort(e+1,e+m+1);
	iota(fa+1,fa+n+1,1);
	for(int i=1;i<=m;i++)
	{
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v)st.PB(e[i]),fa[u]=v;
	}
	dfs(0,st,0);

	cout<<ans<<endl;

	return 0;
}