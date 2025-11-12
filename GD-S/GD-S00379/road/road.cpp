#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e4+10,MAXM=2e6+10;
//long long INF=1e17+10;
int n,m,k,fa[MAXN],p[20],cnt,c[20],b[20][MAXN],zxc;
//int hd[MAXN],to[MAXN],nxt[MAXN],fw,vis[20][MAXN],val[MAXN];
long long ans,G;
struct node{
	int U,V,W;
}a[MAXM],A[MAXM];
//void add(int x,int y,int z){
//	nxt[++fw]=hd[x],val[fw]=z;
//	to[fw]=y,hd[x]=fw;
//}
int Find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=Find(fa[x]);
}
int cmp(node x,node y){
	return x.W<y.W;
}
//void ks(){
//	int num=0;
//	for(int i=1;i<=m;i++){
//		int x=a[i].U,y=a[i].V,z=a[i].W;
//		int xx=Find(x),yy=Find(y);
//		if(xx!=yy){
//			num++,fa[xx]=yy,ans+=z;
//			add(x,y,z),add(y,x,z);
//			if(num==n-1) break;
//		}
//	}
//}
void cl(){
	int num=0;
	for(int i=1;i<=m;i++){
		int x=a[i].U,y=a[i].V,z=a[i].W;
		int xx=Find(x),yy=Find(y);
		if(xx!=yy){
			num++,fa[xx]=yy,ans+=z;
			A[num]=a[i];
			if(num==n-1) break;
		}
	}
	m=n-1;
	for(int i=1;i<=m;i++) a[i]=A[i];
}
//void dfs(int x,int fa){
//	for(int i=hd[x];i;i=nxt[i]){
//		int v=to[i],z=val[i],op=0;
//		long long minn=INF;
//		if(v==fa) continue;
//		dfs(v,x);
//		for(int j=1;j<=cnt;j++){
//			vis[p[j]][x]=min(vis[p[j]][x],vis[p[j]][v]);
//			if(minn>1ll*vis[p[j]][v]+1ll*b[p[j]][x]) minn=1ll*vis[p[j]][v]+1ll*b[p[j]][x],op=p[j];
//		}
//		if(minn<z) G+=minn,G-=z,vis[op][x]=0;
//	}
//}
void ks1(int N){
	for(int i=1;i<=N;i++) fa[i]=i;
	sort(a+1,a+1+zxc,cmp);
	int num=0;
	for(int i=1;i<=zxc;i++){
		int x=a[i].U,y=a[i].V,z=a[i].W;
		int xx=Find(x),yy=Find(y);
		if(xx!=yy){
			num++,fa[xx]=yy,G+=z;
			if(num==N-1) break;
		}
	}
	for(int i=1;i<=m;i++) a[i]=A[i];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x,y,z;i<=m;i++) scanf("%d%d%d",&x,&y,&z),a[i]={x,y,z};
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) scanf("%d",&b[i][j]);
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(a+1,a+1+m,cmp),cl();
	for(int i=1;i<=(1<<k)-1;i++){
		zxc=m,cnt=0,G=0;
		for(int j=0;j<k;j++) if((i>>j)&1) p[++cnt]=j+1,G+=c[j+1];
		for(int j=1;j<=cnt;j++){
			for(int z=1;z<=n;z++){
				a[++zxc]={n+j,z,b[p[j]][z]};
				a[++zxc]={z,n+j,b[p[j]][z]};
			}
		}
		ks1(n+cnt);
		if(!ans) ans=G;
		else ans=min(ans,G);
	}
	printf("%lld",ans);
	return 0;
//	for(int i=1;i<=n;i++) fa[i]=i;
//	sort(a+1,a+1+m,cmp),ks();
//	for(int i=0;i<=(1<<k)-1;i++){
//		cnt=0,G=0;
//		for(int j=0;j<k;j++) if((i>>j)&1) p[++cnt]=j+1,G+=c[j+1];
//		for(int j=1;j<=cnt;j++) for(int z=1;z<=n;z++) vis[p[j]][z]=b[p[j]][z];
//		dfs(1,0),sum=min(sum,G);
//	}
//	printf("%lld",ans+sum);
//	return 0;
}
