#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e4+15;
int n,m,k,x,y,z,ret,a[N],d[N],kk[N];
bool vis[N];
struct X{
	int y,w;
	bool operator<(const X &o){return w<o.w;}
}; ;
vector<X>G[N];
queue<X>q;
void dij(){
	memset(d,0x3f,sizeof(d));
	q.push({1,0});
	d[1]=0;
	while(!q.empty())
	{
		X u=q.front();
		q.pop();
		kk[u.y]++;
		for(X v:G[u.y])
		{
			if(d[v.y]>d[u.y]+v.w+a[v.y])
			{
				if(vis[v.y]==0&&a[v.y]==0)vis[v.y]=1,ret+=v.w;
				kk[v.y]++;
				d[v.y]=d[u.y]+v.w+a[v.y];
				q.push({v.y,d[v.y]});
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		G[x].push_back({y,z});
		G[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a[i+n];
		for(int j=1;j<=n;j++)
		{
			cin>>y;
			G[n+i].push_back({j,y});
			G[j].push_back({n+i,y});
		}
	}
	dij();
	for(int i=1;i<=k;i++)if(kk[i+n]>=1)ret+=a[i+n];
	cout<<ret;
	return 0;
}

