#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int n,m,k;
struct Node{
	int u,v,w;
};
vector<Node> g[MAXN];
int price[15][MAXN],c[1000005];
bool vis[10005][10005];
int main(){
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		long long sum=0;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=m;++i){
			int u,v,w;
			cin>>u>>v>>w;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
			vis[u][v]=vis[v][u]=1;
			sum+=w;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(vis[i][j]==0&&vis[j][i]==0&&i!=j){
					sum+=g[i][j].w;
//					cout<<i<<" "<<j<<endl;
					vis[i][j]=vis[j][i]=1;
				}
			}
		}
		cout<<sum<<endl;
	}
	else{
		for(int i=1;i<=m;++i){
			int u,v,w;
			cin>>u>>v>>w;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		for(int i=1;i<=k;++i){
			cin>>c[i];
			for(int j=1;j<=n;++j){
				cin>>price[i][j];
			}
		}
		int sum=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(vis[i][j]==0&&vis[j][i]==0&&i!=j){
//					if(c[i]==0){
//						vis[i][j]=vis[j][i]=1;
//					}
//					else{
						sum+=g[i][j].w;
						vis[i][j]=vis[j][i]=1;
//					}
				}
			}
		}
		cout<<sum<<endl;
	}

	return 0;
}
