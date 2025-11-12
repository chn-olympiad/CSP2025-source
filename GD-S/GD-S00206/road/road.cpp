#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
int W[10050][10050];
int n,m,k;
int a[50][10010];
int c[50];
bool vis[10050];
int minnx[10050];
void dijsktra(int str){
	if(str==n+k)return;
	vis[str]=true;
	int mindis=INF,minpos=INF;
	for(int i=1;i<=n+k;i++)
		if(!vis[i]&&W[i][str]<mindis)
			mindis=W[i][str],minpos=i;
		else
			minnx[i]=W[i][str];
	vis[minpos]=true;
	minnx[minpos]=mindis;
	for(int i=1;i<=n+k;i++){
		if((!vis[i])&&(minnx[i]>mindis+W[i][mindis])){
			vis[i]=true;
			minnx[i]=mindis+W[i][mindis];
			dijsktra(i);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		W[u][v]=w;
		W[v][u]=w;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			W[i][j]=INF;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			W[n+i][j]=a[i][j];
			W[j][n+i]=a[i][j];
		}
	}
	int maxn=-1;
	for(int i=0;i<=n;i++)minnx[i]=INF,vis[i]=false;
	vis[1]=true;
	dijsktra(1);
	cout<<minnx[n];
}
