#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
int u,v,w,a[10005][10005];
int c[15],d[10005];
int minn=(1<<29);
long long ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++) a[i][i]=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=a[v][u]=w;
		minn=min(w,minn);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]==0||c[i]<minn){
			for(int p=1;p<=n;p++){
				scanf("%d",&d[p]);
				for(int qq=1;qq<=n;qq++){
					if(qq!=p){
						a[qq][p]=a[p][qq]=d[p]*2;
					}
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]>a[i][k]+a[k][j]){
					a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]<0x3f3f){
				ans=ans+a[i][j];
			}
		}
	}
	printf("%lld",ans/2);
	return 0;
}
