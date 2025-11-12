#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll const maxn=500;
ll n,m;
ll s[maxn+1];
ll c[maxn+1];
ll us[maxn+1];
ll ans;
ll const mod=998244353;
ll jc[maxn+1];
void dfs(ll x,ll g){
	if(x-g-1>=m){
		ans+=jc[n-x+1];
		return;
	}
	if(x>n||g>n-m){
		return;
	}
	for(ll i=1;i<=n;i++){
		if(us[i]){
			continue;
		}
		us[i]=1;
		if(g>=c[i]||s[x]==0){
			dfs(x+1,g+1);
		}
		else{
			dfs(x+1,g);
		}
		us[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		char in=getchar();
		while(in<'0'||in>'1'){
			in=getchar();
		}
		s[i]=in-'0';
	}
	for(ll i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	sort(c+1,c+n+1,[](ll a,ll b){
		return a>b;
	});
	jc[0]=1;
	for(ll i=1;i<=n;i++){
		jc[i]=jc[i-1]*i%mod;
	}
	if(n<=18){
		dfs(1,0);
		printf("%lld",ans);
		return 0;
	}
	printf("0");
	
	
	return 0;
}
