#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,M=2e6+5;
int n,m,k,fa[1<<11][N],c[11];
ll ans[1<<11],res=1e18,a[11][N],sum[11],minn[11],minp[11];
int sp=0,f[11];
struct Edge{
	ll u,v,w;
	bool operator < (const Edge p)const{
		return w<p.w;
	}
}e[M],ne[11][N],uf[M],ut[M];//ne:ÐÂµÄuf
void turn(int t){
	for(int i=1; i<=k; i++){
		f[i]=(t&1);
		t>>=1;
	}
}
int ya(){
	int tt=0;
	for(int i=1; i<=k; i++) tt+=1<<(i-1);
	return tt;
}
int findd(int a,int zt){
	if(a==fa[zt][a]) return a;
	return fa[zt][a]=findd(fa[zt][a],zt);
}
ll solvee(int zt){
	turn(zt);
	ll ans=0;
	for(int i=1; i<=k; i++)
		ans+=c[i]*f[i];
	for(int i=1; i<=k; i++){
		int cnt=n-1;
		if(f[i]){//have a new tu,make the mintree
			int root=minp[i];
			for(int j=1; j<=n; j++){
				if(j==root) continue;
				uf[++cnt]={root,j,a[i][j]+a[i][root]};
			}
			int cnt0=0;
			sort(uf+1,uf+cnt+1);
			for(int j=1; j<=n; j++) fa[zt][j]=j;
			for(int j=1;j<=cnt; j++){
				int x=findd(uf[j].u,zt),y=findd(uf[j].v,zt);
				if(x==y){
					continue;
				}
				fa[zt][x]=y;
				ut[j]=uf[j];
				ans+=uf[j].w;
				cnt0++;
				if(cnt0>=n-1) break;
			}
			for(int j=1; j<=n-1; j++) uf[j]=ut[j];
		}
		
		
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int z=0; z<(1<<10); z++)
		for(int i=1; i<=n; i++)
			fa[z][i]=i;
	for(int i=1; i<=10; i++) minn[i]=1e18;
	for(int i=1; i<=m; i++){
		scanf("%lld %lld %lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1; i<=k; i++){
		scanf("%lld",&c[i]);
		sp|=c[i];
		for(int j=1; j<=n; j++){
			scanf("%lld",&a[i][j]),sp|=a[i][j];
			if(a[i][j]<minn[i]){
				minn[i]=min(minn[i],a[i][j]);
				minp[i]=i;
			}
			sum[i]+=a[i][j];
		}
	}
	sort(e+1,e+m+1);
	int cnt0=0;
	for(int i=1; i<=m; i++){
		int x=findd(e[i].u,0),y=findd(e[i].v,0);
		if(x==y) continue;
		fa[0][x]=y;
		uf[i]=e[i];
		ans[0]+=e[i].w;
		cnt0++;
		if(cnt0>=n-1) break;
	}
	if(k==0){
		printf("%lld",ans[0]);
		return 0;
	}
	if(sp==0){
		printf("0");
		return 0;
	}
	res=ans[0];
	for(int i=1; i<(1<<k); i++){
		res=min(solvee(i),res);
	}
	printf("%lld",res);
	return 0;
}


