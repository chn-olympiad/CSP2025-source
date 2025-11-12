#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e4+10,M=3e6+10;
int a[12][N];
struct edg{
	int u,v,w;
}e[M];
bool cmp(edg x,edg y){
	return x.w<y.w;
}
int fa[N];
int find(int x){
	if(x!=fa[x])fa[x]=find(fa[x]);
	return fa[x];
}
int lazy[12];
int q[1010][1010];
int qq[1010][1010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(n<=1009){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				q[i][j]=-1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	if(k==0){
		sort(e+1,e+1+m,cmp);
		int cnt=0;
		long long ans=0;
		int x=0,y=0,xx=0,yy=0;
		for(int i=1;i<=m;i++){
			x=e[i].u;
			y=e[i].v;
			xx=find(x);
			yy=find(y);
			if(xx!=yy){
				fa[xx]=yy;
				cnt++;
				ans+=e[i].w;
			}
			if(cnt==n-1)break;
		}
		printf("%lld",ans);
		return 0;
	}
	if(n<=1009){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				for(int l=j+1;l<=n;l++){
					if(q[j][l]==-1)q[j][l]=a[i][j]+a[i][l];
					else q[j][l]=min(q[j][l],a[i][j]+a[i][l]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				m++;
				e[m].u=i;
				e[m].v=j;
				e[m].w=q[i][j];
			}
		}
		sort(e+1,e+1+m,cmp);
		int cnt=0;
		long long ans=0;
		int x=0,y=0,xx=0,yy=0;
		for(int i=1;i<=m;i++){
			x=e[i].u;
			y=e[i].v;
			xx=find(x);
			yy=find(y);
			if(xx!=yy){
				cnt++;
				ans+=e[i].w;
				fa[xx]=yy;
			}
			if(cnt==n-1)break;
		}
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

15
*/
