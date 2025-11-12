#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans;
const ll inf=1000000000000000000ll;
const int MAXN=20005;
int n,m,k,N,c[15],a[15][MAXN],BIT[MAXN];
int father[MAXN],siz[MAXN];
struct edge{
	int u,v,w;
}E1[1000005],E2[200005];
int cnt;
inline bool cmp(edge a,edge b){
	return a.w<b.w; 
}
int GetFather(int v){
	if(father[v]==v)return v;
	else return father[v]=GetFather(father[v]);
}
int nowcnt;
inline int Merge(int x,int y,int w){
	int fx=GetFather(x),fy=GetFather(y);
	if(siz[fx]<siz[fy])swap(fx,fy);
	if(fx!=fy){
		father[fy]=fx;nowcnt++;
		siz[fx]=siz[fx]+siz[fy];
		return w;
	} 
	return 0;
}
inline ll MST(int S){
	for(int i=1;i<=n+k;i++)father[i]=i,siz[i]=1;
	int Need=n+BIT[S]-1;
	nowcnt=0;
	ll Sum=0;
	for(int i=1;i<=k;i++){
		if((1<<(i-1))&S)Sum=Sum+c[i]; 
	} 
	for(int i=1;i<=cnt;i++){
		if(E2[i].u<=n||((1<<(E2[i].u-n-1))&S)){
			Sum=Sum+Merge(E2[i].u,E2[i].v,E2[i].w);
			if(nowcnt==Need)return Sum; 
		}
	}
	return inf;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=2000;i++)BIT[i]=BIT[i-(i&(-i))]+1;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&E1[i].u,&E1[i].v,&E1[i].w);
	}sort(E1+1,E1+m+1,cmp);
	for(int i=1;i<=n;i++)father[i]=i;
	for(int i=1;i<=m;i++){
		int fx=GetFather(E1[i].u),fy=GetFather(E1[i].v);
		if(fx!=fy){
			father[fy]=fx; 
			cnt++;E2[cnt]=E1[i];
		}
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]),cnt++,E2[cnt]=edge{n+i,j,a[i][j]}; 
	}sort(E2+1,E2+cnt+1,cmp);
	ans=inf;
	for(int S=0;S<(1<<k);S++){
		ans=min(ans,MST(S));
	}
	printf("%lld",ans);
	return 0;
}
