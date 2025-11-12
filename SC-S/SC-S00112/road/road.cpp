#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+6;
typedef tuple<int,int,int> tii;
vector<tii>edge;
int fa[maxn],val[11];
int solve(int x)
{
	int i=1,ret=0;
	while(x)
	{
		if(1&x)ret+=val[i];
		x>>=1;i++;
	}
	return ret;
}
int fnd(int x){return fa[x]==x?x:fa[x]=fnd(fa[x]);}
bool ask(int x,int y){return fnd(x)==fnd(y);}
void merge(int x,int y){fa[fnd(x)]=fnd(y);}
long long maxx=LONG_LONG_MAX;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		edge.push_back(make_tuple(w,u,v));
	}
	for(int i=1;i<=k;i++)
	{
		cin>>val[i];
		for(int j=1;j<=n;j++)
		{
			cin>>w;
			edge.push_back(make_tuple(w,j,n+i));
		}
	}
	sort(edge.begin(),edge.end());
	int k1=pow(2,k);
	for(int id=0;id<k1;id++)
	{
		for(int i=1;i<=n+k;i++)fa[i]=i;
		long long ans=solve(id);
		if(ans>=maxx)continue;
		for(int i=0;i<edge.size();i++)
		{
			w=get<0>(edge[i]);u=get<1>(edge[i]);v=get<2>(edge[i]);
			if(v>n&&!(id&(1<<(v-n-1))))continue;
			if(ask(u,v))continue;
			merge(u,v);
			ans+=w;
			if(ans>=maxx)break;
		}
		maxx=min(maxx,ans);
	}
	cout<<maxx;
	return 0;
}