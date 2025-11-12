//GZ-S00376 肖家诺 安顺市第一高级中学 
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n , m , k1 , w[10005][10005] , c[10005] , a[10005][10005];
bool vis[10005]

	


// city road countryside 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k1);
	int ci,co,cv;
	memset(w,127,sizeof(w));
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&ci,&co,&cv);w[co][ci]=w[ci][co]=cv;
	}
	for(int i=1;i<=n;i++)w[i][i]=0;
	for(int i=1;i<=k1;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
		scanf("%d",&a[i][j]);
		for(int k=j-1;k>=1;k--){
			w[k][j]=w[j][k]=min(w[k][j],a[i][j]+c[i]+a[i][k]);
		}
		}
		
	}	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++){
			
		}
	}
	
	int had=n-1;
	while(had>=1)
	{
		
	}	
	
}
