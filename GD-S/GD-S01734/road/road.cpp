#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cctype>
#define ll long long
#define R register
using namespace std;
const int N=1e4+5,M=1e6+5,inf=2e9;
int n,m,k,c[15],a[15][N],Mx=0,st,f[N],s,dis[1005][1005],cnt;
ll ans;
bool bz[15];
struct edge{
	int x,y,dis;
}e[2*M],t[M];

void rd(int &x){
	x=0ll;
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
	return;
}

bool cmp(edge x,edge y){
	return ((x.dis<y.dis)?1:0);
}

int fd(int x){
	if(f[x]!=x) f[x]=fd(f[x]);
	return f[x];
}

void dfs(int x,ll cst){
	if(x>k){
		s=0,cnt=1;
		for(R int i=1;i<=n;i++){
			f[i]=i;
			for(R int j=i+1;j<=n;j++) t[++s].x=i,t[s].y=j,t[s].dis=dis[i][j];
		}
		sort(t+1,t+s+1,cmp);
		for(R int i=1;i<=s&&cnt<n&&cst<ans;i++){
			if(fd(t[i].x)==fd(t[i].y)) continue;
			cnt++;
			f[fd(t[i].x)]=fd(t[i].y);
			cst+=t[i].dis;
		}
		ans=min(ans,cst);
		return;
	}
	dfs(x+1,cst);
	if(cst+c[x]>=ans) return;
	int jl[1005][1005];
	for(R int i=1;i<=n;i++) for(R int j=i;j<=n;j++){
		jl[i][j]=jl[j][i]=dis[i][j];
		dis[i][j]=dis[j][i]=min(dis[i][j],a[x][i]+a[x][j]);
	}
	dfs(x+1,cst+c[x]);
	for(R int i=1;i<=n;i++) for(R int j=i;j<=n;j++) dis[i][j]=dis[j][i]=jl[i][j];
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	rd(n),rd(m),rd(k);
	for(R int i=1;i<=m;i++) rd(e[i].x),rd(e[i].y),rd(e[i].dis);
	for(R int i=1;i<=k;i++){
		rd(c[i]),Mx=max(Mx,c[i]);
		for(int j=1;j<=n;j++) rd(a[i][j]);
	}
	for(R int i=1;i<=n;i++) f[i]=i;
	if(Mx==0){
		for(R int i=1;i<=k;i++){
			st=1;
			while(st<=n&&a[i][st]>0) st++;
			for(R int j=1;j<=n;j++){
				if(j==st) continue;
				e[++m].x=st,e[m].y=j,e[m].dis=a[i][j];
			}
		}
	}
	sort(e+1,e+m+1,cmp);
	for(R int i=1;i<=m;i++){
		if(fd(e[i].x)==fd(e[i].y)) continue;
		ans+=e[i].dis;
		f[fd(e[i].x)]=fd(e[i].y);
	}
	if(Mx==0||k==0){
		printf("%lld",ans);
		return 0;
	}
	for(R int i=1;i<n;i++) for(R int j=i+1;j<=n;j++) dis[i][j]=dis[j][i]=inf;
	for(R int i=1;i<=m;i++) dis[e[i].x][e[i].y]=dis[e[i].y][e[i].x]=min(dis[e[i].x][e[i].y],e[i].dis);
	dfs(1,0ll);
	printf("%lld",ans);
	return 0;
}
