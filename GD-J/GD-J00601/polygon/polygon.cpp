#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
#define mod 998244353
#define ari(x) array<int,(x)>
#define lcm(x,y) x/__gcd(x,y)*y
#define lowbit(x) ((x) & -(x))

const int N = 5005;
ll f[N][N],ans;
int s[N],a[N],n;
void dfs(int k,ll sum,int ma){
	if(s[k] + sum <= ma) return;
	if(k == 0){
		ans+=(ma < sum);
		ans%=mod;
		return;
	}
	dfs(k-1,sum,ma);
	dfs(k-1,sum+a[k],ma);
}
void init(){//C_n^k
	f[0][0] = 1;
	for(int i = 1;i <= n;i++){
		f[i][0] = 1;
		for(int j = 1;j <= i;j++){
			f[i][j] = f[i-1][j] % mod + f[i-1][j-1] % mod;
			f[i][j]%=mod;
		}
	}
}
void solve(){//15~17:max_ai=1
	init();
	ll ans = 0;
	for(int i = 3;i <= n;i++) ans = (ans + f[n][i]) % mod;
	cout<<ans % mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	int ma = 0;
	for(int i = 1;i <= n;i++) cin>>a[i],ma = max(ma,a[i]);
	if(ma == 1){
		solve();
		return 0;
	}
	//1~10:n<=20,max_ai<=100
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++) s[i] = s[i-1] + a[i];
	for(int i=3;i<=n;i++) if(s[i-1] > a[i]) dfs(i-1,0ll,a[i]);
	cout<<ans % mod;
	return 0;
}
