#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20;
struct node{
	int x,y,z;
}d[2*N];
int n,m,k,cnt;
bool cmp(node x,node y) {
	return x.z<y.z;
}
int f[N];
int gf(int v) {
	if(f[v]==v) return f[v];
	return f[v]=gf(f[v]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=m;i++) {
		int v,u,w;scanf("%d%d%d",&v,&u,&w);
		d[++cnt].x=v,d[cnt].y=u,d[cnt].z=w;	
	}
	for(int i=1;i<=k;i++) {
		int c;scanf("%d",&c);
		d[++cnt].x=0,d[cnt].y=n+i,d[cnt].z=c;
		for(int j=1;j<=n;j++) {
			int x;scanf("%d",&x);
			d[++cnt].x=n+i,d[cnt].y=j,d[cnt].z=x;
		}
	}
	sort(d+1,d+cnt+1,cmp);
	long long ans=0;
	for(int i=1;i<=cnt;i++) {
		int fx=gf(d[i].x),fy=gf(d[i].y);
		if(fx!=fy) {
			f[fx]=fy;
			ans+=d[i].z;
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/

