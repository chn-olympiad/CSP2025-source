#include<bits/stdc++.h>
using namespace std;
long long n,m,k,pr[5010][5010],cnt,o,w;
vector<long long> g[10010];
vector<long long> xiu[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		pr[u][v]=pr[v][u]=w;
	}
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int l=j+1;l<=n;l++)pr[i][l]=min(pr[i][l],pr[i][j]+pr[j][l]);
	for(int i=1;i<=k;i++){
		cin>>o;
		for(int j=1;j<=n;j++)cin>>w;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			pr[i][j]=min(pr[i][j],pr[i+1][j-1]+pr[j-1][j]);
		}
	}
	cout<<pr[1][n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
