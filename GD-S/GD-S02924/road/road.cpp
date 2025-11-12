#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long f[1000005]={0};
long long a[15][1000005]={0};
long long c[15];
long long ans=0x7fffffff;
int g;
struct road{
	long long u,v,w;
};
road arr[100000005];
int vis1[100000005]={0},vis2[100000005]={0};//检查重复点，检查重复边 
int ch[15]={0};//检查是否城市化 

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&arr[i].u,&arr[i].v,&arr[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	g=m+k*n;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			arr[m+(i-1)*n+j].u=j;
			arr[m+(i-1)*n+j].v=n+i;
			arr[m+(i-1)*n+j].w=a[i][j];
		}
	}
	cout<<0;
	return 0;
} 
