#include<bits/stdc++.h>
#define int long long
//#define ll long long
using namespace std;
const int N=1e4+10,M=1e7+10;
int ans=1e18,n,m,k,c[15],a[15][N],f[N];
struct px{
	int u,v,w;
}e[M];
bool cmp(px x,px y){
	return x.w<y.w;
}
int find(int fa){
	if(f[fa]==fa) return fa;
	return f[fa]=find(f[fa]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	for(int S=0;S<1<<k;S++){
		int sum=0,cnt=n;
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=0;(1<<i)<=S;i++){
			if((S>>i)&1){
				sum+=c[i+1];
				for(int j=1;j<n;j++){
					for(int k=j+1;k<=n;k++){
						e[++cnt]={j,k,a[i+1][j]+a[i+1][k]};
					}
				}
			}
		}
		sort(e+1,e+cnt+1,cmp);
		int num=0;
		for(int i=1;i<=cnt;i++){
			if(find(e[i].u)!=find(e[i].v)){
				num++;
				sum+=e[i].w;
				f[find(e[i].u)]=find(e[i].v);
			}
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
} 
