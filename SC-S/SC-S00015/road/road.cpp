#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,m,k;
int r[1005][1005];
int c[15];
int a[15][1005];
int q[1005][1005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(r,-1,sizeof(r));
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		r[u][v]=w;
		r[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		q[i][i]=0;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int minn=INT_MAX;
			for(int t=1;t<=k;t++){
				minn=min(minn,c[t]+a[t][i]+a[t][j]);
			}
			for(int p=1;p<=n;p++){
				if(i==p||p==j) continue;
				if(r[i][j]==-1){
					if(r[i][p]==-1||r[p][j]==-1){
						continue;
					}
					r[i][j]=min(r[i][p]+r[p][j],minn);
				}else{
					r[i][j]=min(r[i][p]+r[p][j],min(minn,r[i][j]));
				}
			}
		}
	}
	printf("%d",r[1][n]);
	return 0;
}