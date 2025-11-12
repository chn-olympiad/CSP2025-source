#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,w[15],cnt,sum,ans = 1e18,ss,xx,f[10015];
struct edge{
	ll a,b,c;
}e[1100005];
ll func(ll x){
	if(f[x] == x){
		return x;
	}else{
		ll y = func(f[x]);
		f[x] = y;
		return y;
	}
}
bool cmp(edge A,edge B){
	return A.c < B.c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i = 1; i <= m; i++){
		ll a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a == b) continue;
		e[++cnt].a = a,e[cnt].b = b,e[cnt].c = c;
	}
	for(int i = 1; i <= k; i++){
		scanf("%lld",&w[i]);
		for(int j = 1; j <= n; j++){
			ll c;
			scanf("%lld",&c);
			e[++cnt].a = i+n,e[cnt].b = j,e[cnt].c = c;
		}
	}
	sort(e+1,e+1+cnt,cmp);
	for(int s = 0; s < (1<<k); s++){
		ss = 0,xx = 0,sum = 0;
		for(int i = 1; i <= k; i++){
			if((s&(1 << (i-1))) != 0){
				sum += w[i];
				xx++;
			}
		}
		for(int i = 1; i <= n+k; i++){
			f[i] = i;
		}
		for(int i = 1; i <= cnt; i++){
			if(ss == n+xx-1) break;
			ll a = e[i].a,b = e[i].b,c = e[i].c;
			if((e[i].a > n && (s&(1<<(e[i].a-1-n))) == 0) || (e[i].b > n && (s&(1<<(e[i].b-1))) == 0)){
				continue;	
			} 
			ll l = func(a),r = func(b);
			if(l != r){
				sum += c;
				ss++;
				f[l] = r;
			}
		}
		ans = min(ans,sum);
//		printf("CCF %lld %lld %lld %lld %lld\n",sum,s,n,xx,ss);
	}
	printf("%lld",ans);
	return 0;
}
/*
          _____    ____
   /\    |        /    \
  /__\   |_____   |    |
 /    \  |        |    |
/      \ |        \____/  

*/
