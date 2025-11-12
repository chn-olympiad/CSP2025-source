#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[3][101][101][101];
const int N=2e5+7;
struct dada{
	ll a,b,c,mx;
}a[N];
ll b[10],sum;
bool cmp(dada a,dada b){
	return a.mx>b.mx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	scanf("%lld",&t);
	while(t--){
		ll n,f1,f2;
		scanf("%lld",&n);
		memset(a,0,sizeof(a));
		for(ll i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
			a[i].mx=max(a[i].a,max(a[i].b,a[i].c));
			if(a[i].b)f1=1;
			if(a[i].c)f2=1;
		}sort(a+1,a+1+n,cmp);
		if(f1==f2&&f1==0){
			ll sum=0;
			for(int i=1;i<=n>>1;i++){
				sum+=a[i].mx;
			}
			printf("%lld\n",sum);
		}else if(n<202){
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++){
				for(int x=0;x<=(n>>1);x++){
					for(int y=0;y<=(n>>1);y++){
						for(int z=0;z<=(n>>1);z++){
							dp[i&1][x][y][z]=max(dp[(i-1)&1][x][y][z],max(x>0?dp[(i-1)&1][x-1][y][z]+a[i].a:0,max(y>0?dp[(i-1)&1][x][y-1][z]+a[i].b:0,x>0?dp[(i-1)&1][x][y][z-1]+a[i].c:0)));
						}
					}
				}
			}
			printf("%lld\n",dp[n&1][(n>>1)][(n>>1)][(n>>1)]);
		}
	}
	return 0;
} 
