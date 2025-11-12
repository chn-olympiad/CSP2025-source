#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k;
struct Edge{
	ll u,v,w;
}a[1500010],b[1500010];
ll F[10010];
ll find(ll x){
	if(F[x]==x) return x;
	return F[x]=find(F[x]);
}
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
void solve1(){
	ll ans=0;
	sort(a+1,a+m+1,cmp);
	for(ll i=1;i<=m;i++){
		ll fx=find(a[i].u);
		ll fy=find(a[i].v);
		if(fx==fy) continue;
		ans+=a[i].w;
		F[fx]=fy;
	}
	printf("%lld",ans);
}
ll ans=1e18;
ll c[15],cst[15][10010];
ll cal(ll cnt){
	for(ll i=1;i<=cnt;i++) b[i]=a[i];
	sort(b+1,b+cnt+1,cmp);
	for(ll i=1;i<=n+k;i++) F[i]=i;
	ll sum=0;
	for(ll i=1;i<=cnt;i++){
		ll fx=find(b[i].u);
		ll fy=find(b[i].v);
		if(fx==fy) continue;
		sum+=b[i].w;
		F[fx]=fy;
	}
	return sum;
}
void dfs(ll now,ll cnt,ll sum){
	if(sum>ans) return;
	if(now>k){
		ans=min(ans,sum+cal(cnt));
		return;
	}
	dfs(now+1,cnt,sum);
	for(ll i=cnt+1;i<=cnt+n;i++){
		a[i]=(Edge){n+now,i-cnt,cst[now][i-cnt]};
	}
	dfs(now+1,cnt+n,sum+c[now]);
}
void solve2(){
	ans=1e18;
	dfs(1,m,0);
	printf("%lld",ans);
}
ll cishu[15],shuzhi[15];
void solve3(){
	ll all=m;
	for(ll i=1;i<=k;i++){
		for(ll j=all+1;j<=all+n;j++){
			a[j]=(Edge){i+n,j-all,cst[i][j-all]};
		}
		all+=n;
	}
	ll daan=0;
	sort(a+1,a+m+n*k+1,cmp);
	for(ll i=1;i<=n+k;i++) F[i]=i;
	for(ll i=1;i<=m+n*k;i++){
		ll fx=find(a[i].u),fy=find(a[i].v);
		if(fx==fy) continue;
		F[fx]=fy;
		daan+=a[i].w;
		if(a[i].u>n){
			cishu[a[i].u-n]++;
			shuzhi[a[i].u-n]=a[i].w;
		}
	}
	for(ll i=1;i<=k;i++){
		if(cishu[i]==1) daan-=shuzhi[i];
	}
	printf("%lld",daan);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=n;i++) F[i]=i;
	for(ll i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	if(k==0) solve1();
	else{
		bool A=true,B=true;
		for(ll i=1;i<=k;i++){
			scanf("%lld",&c[i]);
			if(c[i]!=0) A=false,B=false;
			for(ll j=1;j<=n;j++){
				scanf("%lld",&cst[i][j]);
				if(cst[i][j]!=0) A=false;
			}
		}
		if(A) printf("0");
		else if(k<=5) solve2();
		else if(B) solve3();
	}
	return 0;
}
