#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
const int N=1e4+10;
LL n,m,p,i,j,k,a,b,c,d[15],z[N],ans;
bool t[15];
struct U{
	LL a,b,c;
}tu[N*200];
void cun(LL a,LL b,LL c){
	tu[++k].a=a,tu[k].b=b,tu[k].c=c;
}
bool cmp(U x,U y){
	return x.c<y.c;
}
LL found(LL x){
	if(z[x]==x) return x;
	return z[x]=found(z[x]);
}
void dfs(LL a,LL l){
	if(a>p){
		LL i,c,b;
		for(i=1;i<=n+p;i++){
			z[i]=i;
		}
		for(i=1;i<=k;i++){
			c=tu[i].a,b=tu[i].b;
			if(c>n){
				if(!t[c-n]) continue;
			}
			if(found(c)==found(b)) continue;
			z[found(c)]=found(b),l+=tu[i].c;
		}
		c=found(1);
		for(i=2;i<=n;i++){
			if(found(i)!=c) return;
		}
		ans=min(ans,l);
		return;
	}
	dfs(a+1,l);
	t[a]=1;
	dfs(a+1,l+d[a]);
	t[a]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&p);
	for(i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a,&b,&c);
		cun(a,b,c);
	}
	for(i=1;i<=p;i++){
		scanf("%lld",&d[i]);
		for(j=1;j<=n;j++){
			scanf("%lld",&c);
			cun(n+i,j,c);
		}
	}
	sort(tu+1,tu+k+1,cmp);
	ans=1e18+10;
	dfs(1,0);
	printf("%lld",ans);
	return 0; 
}
