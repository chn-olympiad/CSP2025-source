#include <bits/stdc++.h>
using namespace std;
int n,m,k;
const int INF = 0x3f3f3f3f;

struct Node{
	int v,w;
};

vector <Node> Edge[10020];
int a[15][10005];
int ans[10020];
bool vis[10020];
//int c[15];
long long sum;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		Edge[u].push_back({v,w});
		sum += w;
	}
	for(int i = 1;i <= k;i++){
		int c;
		cin>>c;
		for(int j = 1;j <= n;j++){
			cin>>a[i][j];
			a[i][j] += c;
			Edge[m+i].push_back({j,a[i][j]});
		}
	}
	
	memset(ans,0x3f3f3f3f,sizeof(ans));
	ans[1] = 0;
	vis[1] = true;
	for(int i = 1;i <= n+k;i++){
		if(vis[i]){
			for(int j = 0;j < Edge[i].size();j++){
				Node t = Edge[i][j];
				int u = i,v = t.v,w = t.w;
				if(ans[v] > ans[u]+w) {
					ans[v] = ans[u]+w;
					vis[v] = true;
				}
			}
		} 
	}
	cout<<sum;
//	for(int i = 1;i <= n+k;i++){
//		cout<<ans[i]<<' ';
//	}
//	
//	for(int i = 1;i <= n+k;i++){
//		cout<<"i="<<i<<' ';
//		for(int j = 0;j < Edge[i].size();j++){
//			printf("%d->%d:%d ",i,Edge[i][j].v,Edge[i][j].w);
//		}
//		cout<<endl;
//	}
	return 0;
}
