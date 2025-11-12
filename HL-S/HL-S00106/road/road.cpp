#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
struct node{
	int u,v,w;
}a[1000005];
int b[11][1005],d[10005];
ll f[1005][1005];
bool g[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		f[a[i].u][a[i].v]=a[i].w;
		f[a[i].v][a[i].u]=a[i].w;
	}
	int p;
	for(int i=1;i<=k;i++){
		scanf("%d",&p);
		for(int i=1;i<=n;i++){
			scanf("%d",&b[k][i]);
			f[k][i]=b[k][i];
			f[i][k]=b[k][i];
		}
	}
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	int mini=1;
	for(int q=1;q<=n;q++){
		for(int i=1;i<=n;i++){
			if(g[i]==0&&d[i]<d[mini]){
				mini=i;
			}
		}
		g[mini]=1;
		for(int i=1;i<=n;i++){
			if(g[i]==0&&d[i]>d[mini]+f[mini][i]){
				d[i]=d[mini]+f[mini][i];
				g[i]=1;
			}
		}
	}
	printf("%lld",f[n]);
	return 0;
}