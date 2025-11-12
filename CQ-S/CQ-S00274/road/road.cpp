#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5,N=1e4+5;
struct no{
	int x,y;
	long long w;
}a[M];
int n,m,k,fa[N],cnt,f,tmp;
long long ans=0,d[N],aj[13][N],c[13],b[1005][1005];
bool cmp(no a,no b){
	return a.w<b.w;
}
int find(int x){
	if(x==fa[x])return fa[x];
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]!=0)f=1;
		for(int j=1;j<=n;j++){
			scanf("%lld",&aj[i][j]);
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	if(k==0){
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;i++){
			int fx=find(a[i].x),fy=find(a[i].y);
			if(fx!=fy){
				fa[fx]=fy;
				ans+=a[i].w;
				cnt++;
				if(cnt==n-1)break;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	if(n<=1000){//prim
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)b[i][j]=5e9;
		for(int i=1;i<=m;i++)
			b[a[i].x][a[i].y]=b[a[i].y][a[i].x]=a[i].w;
		for(int i=1;i<=k;i++){
			for(int j=1;j<n;j++)
				for(int t=j+1;t<=n;t++)
					b[t][j]=b[j][t]=min(b[j][t],c[i]+aj[i][j]+aj[i][t]);
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				a[++tmp]=(no){i,j,b[i][j]};
			}
		}
		sort(a+1,a+1+tmp,cmp);
		for(int i=1;i<=tmp;i++){
			int fx=find(a[i].x),fy=find(a[i].y);
			if(fx!=fy){
				fa[fx]=fy;
				ans+=a[i].w;
				cnt++;
				if(cnt==n-1)break;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	
	return 0;
}
