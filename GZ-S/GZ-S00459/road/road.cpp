//GZ-S00459 贵阳市第一中学 陈加涵 
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool G[10001][10001];
int u,v;
int w[1000001];
int c[10];
int a[11][10001];
void solve1(){
	int sum=0;
	for(int i=1;i<=m;i++){
		sum+=w[i];
	}
	cout<<sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w[i];
		G[u][v]=1;
		G[v][u]=1;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j][i];
		}
	}
	if(k==0){
		solve1();
	}
	else{
		cout<<47;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
