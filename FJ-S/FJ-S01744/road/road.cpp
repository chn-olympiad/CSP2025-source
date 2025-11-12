/*
bushi 这题咋这么抽象啊 qwq.
要是绿题以下我就彻底炸了
部分分:  1~10,13,14,17,18
56pts 
*/
#include <bits/stdc++.h>
using namespace std;

const int N=2e4+10,M=2e6+10;

struct Edge{
	int u,v,w;
}edge[M],e[M];

int n,m,k,c[15],a[15][N],f[N],sz[N];
long long ans;

inline bool operator<(Edge x,Edge y){
	return x.w<y.w;
}

int father(int x){
	return f[x]==x?x:f[x]=father(f[x]);
}

inline long long solve(int num){
	long long res=0;
	int tot=0;
	for(int i=1;i<=m;i++)
		e[++tot]=edge[i];
	for(int i=1;i<=k;i++)
		if((num>>i-1)&1){
			res+=c[i];
			for(int j=1;j<=n;j++)
				e[++tot]={i+n,j,a[i][j]};
		}
	for(int i=1;i<=n+k;i++)
		f[i]=i,sz[i]=1;
	sort(e+1,e+tot+1);
	for(int i=1;i<=tot;i++){
		int fx=father(e[i].u),fy=father(e[i].v);
		if(fx!=fy){
			res+=e[i].w;
			if(sz[fx]<sz[fy])
				swap(fx,fy);
			f[fy]=fx,sz[fx]+=sz[fy];
		}
	}
	return res;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool flag=1;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]>0)
			flag=0;
		int mn=1e9;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			mn=min(mn,a[i][j]);
		}
		if(mn>0)
			flag=0;
	}
	if(flag){
		long long sum=0;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				edge[++m]={n+i,j,a[i][j]};
		sort(edge+1,edge+m+1);
		for(int i=1;i<=n+k;i++)
			f[i]=i,sz[i]=1;
		for(int i=1;i<=m;i++){
			int fx=father(edge[i].u),fy=father(edge[i].v);
			if(fx!=fy){
				sum+=edge[i].w;
				if(sz[fx]<sz[fy])
					swap(fx,fy);
				f[fy]=fx,sz[fx]+=sz[fy];
			}
		}
		printf("%lld",sum);
	}else{
		ans=1e18;
		for(int i=0;i<1<<k;i++)
			ans=min(ans,solve(i));
		printf("%lld",ans);
	}
	return 0;
}
