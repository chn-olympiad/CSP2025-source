#include<bits/stdc++.h>//要强联通 
using namespace std;
const int N=1e4+1,M=1e6+1;
int n,m,k;//城市,道路,乡镇数量
struct nod{
	int v,w;
};
vector<nod>g[M];
int c[11],a[11][N];//镇进行城市化改造的费用,在该乡镇与原有的城市间建造道路的费用
bool vid[N];

int sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		sum+=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			sum+=a[i][j];
		}
		sum+=c[i];
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
