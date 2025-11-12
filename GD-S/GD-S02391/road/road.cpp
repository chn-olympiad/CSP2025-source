#include<bits/stdc++.h>
using namespace std;;
const int Q=1e4+25;
int N,M,K,minn,a[Q][Q],b[Q][Q],c[15][Q];
int main(){
	freopen("rode.in","r",stdin);
	freopen("rode.out","w",stdout);
	scanf("%d%d%d",&N,&M,&K);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			a[i][j]=INT_MAX,b[i][j]=-1;
	for(int i=1;i<=K;i++)
		b[i][0]=-1;
	for(int i=1;i<=M;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=min(a[u][v],w);
		a[v][u]=min(a[v][u],w);
		minn+=w,b[u][v]=1,b[v][u]=1;
	}
	for(int i=1;i<=K;i++)
	{
		scanf("%d",&c[i][0]);
		for(int j=1;j<=N;j++)
			scanf("%d",&c[i][j]);
	}
	printf("%d",minn);
	return 0;
}
