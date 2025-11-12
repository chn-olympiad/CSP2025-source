#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
#define N 5005
#define PII pair<ll, ll>
#define INF (ll)1e18

using namespace std;
inline ll rd(){
	ll res=0, f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48), ch=getchar();
	return res*f;
}
const ll mod=998244353;
ll n, a[N], dp[N][N*3], sum, ans, pre[N*3], mx;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n=rd();
	for(int i=1; i<=n; i++) a[i]=rd(), mx=max(mx, a[i]);
	sort(a+1, a+n+1);
	dp[0][0]=pre[0]=1;
	for(int i=1; i<=n; i++){
		sum+=a[i], ans=(ans*2)%mod;
		for(int j=a[i]; j<=min(sum, 2*mx+a[i]); j++){
//			for(int k=0; k<i; k++) dp[i][j]=(dp[i][j]+dp[k][j-a[i]])%mod;
			dp[i][j]=pre[j-a[i]];
		}
//		puts("");
		if(sum>2*mx) for(int j=2*mx+1; j<=min(sum, 2*mx+a[i]); j++) ans=(ans+dp[i][j])%mod, dp[i][j]=0;
		for(int j=0; j<=min(sum, 2*mx); j++) pre[j]=(pre[j]+dp[i][j])%mod;
	}
//	cout<<ans<<endl;
	for(int i=1; i<=n; i++){
//		for(int j=1; j<=sum; j++) cout<<dp[i][j]<<' ';
//		puts("");
//		cout<<2*mx<<' '<<2*a[i]+1<<' '<<sum<<endl;
		for(int j=2*a[i]+1; j<=min(sum, 2*mx); j++) ans=(ans+dp[i][j])%mod;//, cout<<dp[i][j]<<' ';
//		puts("");
	}
	printf("%lld\n", ans);

	return 0;
}
/*
2025-11-01 10:21 AK CSP-J 2025! 

愿下午的 CSP-S 能同样拿到我想要的成绩

所有梦想都会实现 
*/

