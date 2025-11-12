#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n,a[5005];
long long f[5005],ans;
long long dp[5005][5005][3];
void dfs(int x,int cnt,long long y,long long z,int ok){
	if(x>n) return;
	if(z>y*2&&cnt>=3&&ok){
		ans = (ans+1)%mod;
	}
	dfs(x+1,cnt,y,z,0);
	dfs(x+1,cnt+1,max(y,a[x+1]),z+a[x+1],1);
}
bool check(){
	for(int i=1; i<=n; i++){
		if(a[i]!=1) return 0;
	}
	return 1;
}
long long ny(long long x,long long y){
	long long ans = 1;
	while(y){
		if(y&1) ans = ans*x%mod;
		x = x*x%mod;
		y >>= 1;
	}
	return ans;
}
long long C(int x,int y){
	return f[y]*ny(f[y-x],mod-2)%mod*ny(f[x],mod-2)%mod;
}
int main(){
	//100pts
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	if(check()){
		f[0] = 1;
		for(int i=1; i<=n; i++){
			f[i] = f[i-1]*i%mod;
		}
		for(int i=3; i<=n; i++){
			ans = (ans+C(i,n))%mod;
		}
		cout << ans;
	}else if(n<=20){
		dfs(0,0,0*1ll,0*1ll,0);//pos,all,max,sum,ok;
		cout << ans%mod;
	}else{
		f[0] = 1;
		for(int i=1; i<=n; i++){
			f[i] = f[i-1]*i%mod;
		}
		for(int i=3; i<=n; i++){
			ans = (ans+C(i,n))%mod;
		}
		sort(a+1,a+1+n);
		dp[0][0][0] = 1;
		for(int i=1; i<=n; i++){
			for(int j=0; j<=5000; j++){
				for(int k=0; k<=2; k++) dp[i][j][k] = dp[i-1][j][k];
			}
			for(int j=0; j<=5000; j++){
				if(a[i]+j>5000) break;
				for(int k=1; k<=2; k++){
					if(k==1) dp[i][j+a[i]][k] = (dp[i][j+a[i]][k]+dp[i-1][j][k-1])%mod;
					else dp[i][j+a[i]][k] = ((dp[i][j+a[i]][k]+dp[i-1][j][k-1])%mod+dp[i-1][j][k])%mod;
				}
			}
		}
		int r = n;
		for(int j=5000; j>=1; j--){
			while(j<=a[r]&&r>=1) r--;
			ans = ((ans-dp[n][j][2]*(n-r)%mod)%mod+mod)%mod;
		}
		cout << ans;
	}
	return 0;
}