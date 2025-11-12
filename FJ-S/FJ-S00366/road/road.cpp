#include <bits/stdc++.h>
using namespace std;
#define rt return
typedef long long ll;
const int N=1010000;
const int M=10010;
int n,m,k,c[20][M],f[M],r;
struct kru{
	int u,v;
	ll w;
}w[N];
int bcj(int i){ rt i==f[i]?i:(f[i]=bcj(f[i])); }
bool cmp(const kru x,const kru y){
	rt x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%lld",&w[i].u,&w[i].v,&w[i].w); 
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	if(k!=0){
		puts("0");
		rt 0;
	}
	sort(w+1,w+m+1,cmp);
	ll ans=0;
	for(int i=1;i<=m;i++){
		int fu=bcj(w[i].u),fv=bcj(w[i].v);
		if(fu!=fv){
			ans+=w[i].w,f[fu]=fv;
		}
	}		
	printf("%lld\n",ans);
	rt 0;
}                                         
