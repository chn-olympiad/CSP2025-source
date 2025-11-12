#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>

#define pb push_back

using std::min;
using std::max;
using std::cin;
using std::cout;
using std::sort;

const int N=1e4+15,M=1e6+5;
int n,m,k,u,v,w,c[12],a[12][N];
struct Node{int to,cost;};
bool cmp(Node x,Node y){return x.cost<y.cost;}
std::vector<Node> e[N],ed;
bool vis[N];
long long ans;
int main(){
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u>>v>>w,e[u].pb({v,w}),e[v].pb({u,w});
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j],e[n+i].pb({j,0}),e[j].pb({n+i,0});
	}
	for(int i=1;i<=n+k;i++) sort(e[i].begin(),e[i].end(),cmp);
	for(int i=1;i<=n+k;i++)
		for(int j=i;!vis[j];j=e[j][0].to)vis[j]=1,ans+=e[j][0].cost;
	cout<<ans<<'\n';
	return 0;
}
/*




*/
