#include <iostream>
#define int long long
using namespace std;
int n,m,k;
int ans=0;
int ver[2000005],_next[2000005],head[2000005],edge[2000005];
int tot=0;
void add(int x,int y,int z)
{
	tot++;
	ver[tot]=y;
	edge[tot]=z;
	_next[tot]=head[x];
	head[x]=tot;
}
int _min=(int)1e9;
bool vis[1000005];
void dfs(int x,int sum,int cnt)
{
	if (cnt==n){
		_min=min(_min,sum);
		return;
	}
	for (int i=head[x]; i; i=_next[i]){
		int y=ver[i],z=edge[i];
		if (vis[y]){
			continue;
		}
		vis[i]=vis[y]=1;
//		cout<<i<<" "<<y<<" "<<sum<<" "<<z<<endl;
		dfs(y,sum+z,cnt+1);
		vis[y]=0;
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for (int i=1; i<=m; i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
		ans+=w;
	}
	if (k==0){
		dfs(1,0,1);
		cout<<_min;
		return 0;
	}
	cout<<ans;
	return 0;
}
