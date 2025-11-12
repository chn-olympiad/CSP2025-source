#include<cstdio>
#include<algorithm>
using namespace std;
int Read(){
	int x=0,f=1; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return x*f;
}
long long ReadLL(){
	long long x=0; int f=1; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return x*f;
}
const int N=1e4+5,M=2e6+5,K=15;
#define ll long long
const ll inf=1e18;
int n,m,k,fl[N+10]; ll c[K],a[K][N],ans,Ans,ida[K][N],ta[K][N],Ls[K],r[K],tmp[N]; bool b[15];
int fd(int x){return fl[x]==x?x:fl[x]=fd(fl[x]);}
struct rd{int u,v; ll w;}g[M],gg[N];
bool operator<(rd x,rd y){return x.w<y.w;}
bool cmp(int x,int y){return tmp[x]<tmp[y];}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i){
		g[i].u=Read(); g[i].v=Read();
		g[i].w=ReadLL();
	}
	sort(g+1,g+m+1);
	for(int i=1;i<=n;++i) fl[i]=i;
	for(int i=1,cnt=0,x,y;i<=m;++i){
		x=fd(g[i].u); y=fd(g[i].v);
		if(x!=y){
			fl[x]=y; ++cnt; Ans+=g[i].w;
			gg[cnt]=g[i];
			if(cnt==n-1) break;
		}
	}
	if(!k){printf("%lld",Ans); return 0;}
	for(int i=1;i<=k;++i){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;++j){
			a[i][j]=ReadLL();
			tmp[j]=a[i][j]; ida[i][j]=j;
		}
		sort(ida[i]+1,ida[i]+n+1,cmp);
		//ida[i][j]=第i乡村第j小边对应连接的点
		sort(tmp+1,tmp+n+1);
		for(int j=1;j<=n;++j) ta[i][j]=tmp[j];
		//ta[i][j]=第i乡村第j小边
	}
	for(int i=1,tot=0;i<(1<<k);++i){
//		printf("::::::::%d\n",i);
		tot=0; ans=0;
		for(int j=1;j<=n+k;++j) fl[j]=j;
		for(int j=0;j<k;++j)
			if(i&(1<<j)) Ls[++tot]=j+1,ans+=c[j+1];
		//Ls[j]=第j个乡村 
		for(int j=1;j<=tot;++j) r[Ls[j]]=0;//r[Ls[j]]=第j个乡村选了多少条边
		r[0]=0;
		for(int j=1,cnt=0,x,y,fx,fy,mx=0;cnt<n+tot-1;++j){
			for(int l=1;l<=tot;++l)
				if((r[Ls[l]]<n&&ta[Ls[l]][r[Ls[l]]+1]<ta[mx][r[mx]+1])||!mx) mx=Ls[l];
//			if(i==1) printf("%d && %d\n",r[0],mx);
			if(mx&&ta[mx][r[mx]+1]<gg[r[0]+1].w){
				x=mx+n; y=ida[mx][++r[mx]];
//				printf("%d %d %lld\n",x,y,ta[mx][r[mx]+1]);
				fx=fd(x); fy=fd(y);
				if(fx!=fy){
					fl[fx]=fy; ++cnt;
					ans+=ta[mx][r[mx]];
//					printf(":::%lld\n",ans);
				}
			}else if(r[0]<n-1){
				x=gg[r[0]+1].u; y=gg[r[0]+1].v;
//				printf("%d %d %lld\n",x,y,gg[r[0]+1].w);
				fx=fd(x); fy=fd(y); ++r[0];
				if(fx!=fy){
					fl[fx]=fy; ++cnt;
					ans+=gg[r[0]].w;
//					printf(":::%lld\n",ans);
				}
			}
		}
		Ans=min(Ans,ans);
	}
	printf("%lld",Ans);
	return 0;
}
