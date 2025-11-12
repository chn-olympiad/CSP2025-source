#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e6+5, M=1e4+15;

int n,m,k;
struct qwq{
	int a,b,c;
}e[N];
bool cmp(const qwq &x,const qwq &y){
	return x.c<y.c;
}

int f[N];
int getf(int a){
	if(f[a]==a) return a;
	return f[a]=getf(f[a]);
}

void Solve1(){
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
	sort(e+1,e+m+1,cmp);
	LL ans=0;
	int sum=0;
	for(int i=1;i<=m;i++){
		int x=getf(e[i].a), y=getf(e[i].b);
		if(x!=y){
			sum++;
			f[x]=y;
			ans+=e[i].c;
		}
		if(sum==n-1) break;
	}
	printf("%lld\n",ans);
}

int c[15],b[15][M];
int a[M][M];
bool bk[M];

int nw[M],tot;

int dis[M],inq[M];

LL zans=1e18;

void Calc(){
	tot=0;
	for(int i=1;i<=n;i++) nw[++tot]=i;
	for(int i=1;i<=k;i++) if(bk[i]) nw[++tot]=i;
	for(int i=1;i<=n;i++)
		for(int j=n+1;j<=tot;j++)
			a[i][j]=a[j][i]=b[nw[j]][i];
			
	LL ans=0;
	for(int i=n+1;i<=tot;i++) ans+=c[nw[i]];
	// prim
	for(int i=1;i<=tot;i++) inq[i]=0;
	inq[1]=1;
	for(int i=1;i<=tot;i++) dis[i]=a[1][i];
	for(int i=1;i<tot;i++){
		int mn=1e9+1,wh=0;
		for(int j=1;j<=tot;j++)
			if(mn>dis[j] && !inq[j]){
				mn=dis[j];
				wh=j;
			}
		inq[wh]=1;
		ans+=mn;
		if(ans>zans) return;
		for(int j=1;j<=tot;j++)
			if(!inq[j])
				dis[j]=min(dis[j],a[wh][j]);
	}
	
	zans=min(zans,ans);
}

void dfs(int tmp){
	if(tmp>k){
		Calc();
		return;
	}	
	bk[tmp]=0;
	dfs(tmp+1);
	bk[tmp]=1;
	dfs(tmp+1);
}

void Solve2(){
	memset(a,0x3f,sizeof(a));
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=a[v][u]=min(a[u][v],w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) scanf("%d",&b[i][j]);
	}
	dfs(1);
	printf("%lld",zans);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	
	scanf("%d%d%d",&n,&m,&k);
	if(k==0){
		Solve1();
		return 0;
	}
	
	Solve2();
	return 0;
}

