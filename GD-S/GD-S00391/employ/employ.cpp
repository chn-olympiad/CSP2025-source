#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[505],vis[505],ans;
const int mod=998244353;
int fac[505];
char s[505];
void dfs(int t,int sum){
	if(t-1-sum>=m){
		ans=(ans+fac[n-t+1])%mod;
		return ;
	}
	if(t>n){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(sum>=c[i]||s[t]=='0') dfs(t+1,sum+1);
			else dfs(t+1,sum);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=1ll;
	for(int i=1;i<=500;i++){
		fac[i]=(fac[i-1]*i)%mod;
	}
	scanf("%lld%lld",&n,&m);
	cin>>(s+1);
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
