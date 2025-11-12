#include<bits/stdc++.h>
using namespace std;
#define freop(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
#define ll long long
#define ld long double
#define lb(x) (x&-x)
#define re register
#define endl '\n'
#define pii pair<int,int>
#define fir first
#define sec second
const int N=5002,mod=998244353;
int n,a[N],nw,dp[N]={1},ans;

inline int md(int asdf){return asdf-(asdf>=mod)*mod;}

int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	cout.tie(0);
	freop("polygon");
//以上为初始化 
//--------------------------------------
	cin >> n;
	for(int i = 1;i<=n;++i) cin >> a[i];
	sort(a+1,a+n+1),++dp[a[1]],++dp[a[2]],++dp[a[1]+a[2]],nw=4;
	for(int i = 3;i<=n;++i){
		ans=md(ans+nw),nw=md(nw<<1);
		for(int j = 0;j<=a[i];++j) ans=md(ans-dp[j]+mod);
		for(int j = N-1;j>=a[i];--j) dp[j]=md(dp[j]+dp[j-a[i]]);
	}
	cout << ans << endl;
	return 0;
}
/*

*/


