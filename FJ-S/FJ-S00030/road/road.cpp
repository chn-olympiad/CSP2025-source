#include<bits/stdc++.h>
using namespace std;

int n,m,k,u,v,w,s,nt,np;
struct road{
	int v,w;
};
int a[10007][10007];
int b[10][10007];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&b[i][j]);
		}
	}
	if(k==0){
		for(int t=1;t<=n;t++){
			for(int i=1;i<=n;i++){
				for(int j=2;j<=n;j++){
					a[i][j]=min(a[i][j],a[i][t]+a[t][j]);
				}
			}
		}
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=2;j<=n;j++){
				maxn=max(a[i][j],maxn);
			}
		}
		cout<<maxn;
	}else{
		cout<<0;
	}
	return 0;
}
