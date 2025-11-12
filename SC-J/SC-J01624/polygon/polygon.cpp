// 9:48 if i dont finish T4 final,i am a dg
//11:27 OH MY GOD!!!!! acccc
// OH MY GOD I AM SO HAPPY
// I CHECK THE BUG FOR 1.5 HOUR
// i am so happy because i may ak!(maybe,ruguomeiyoujiudangwomeishuo)
//woshinailong,wocaishinailong
// qidaiwo xiawu s group have a good chengji
//neng rang wo shang mi huo da shang ma....
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353, N = 5e3+5;
ll n, a[N], dp[N][N << 1], maxn, ans;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main() {

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	n=read();
	for (ll i = 1; i <= n; i++) a[i]=read();
	sort(a + 1, a + n + 1);
	maxn = a[n];
	for (ll j = 0; j <= 2 * maxn + 2; j++) {
		if (j == 0) dp[1][j] = 2;
		else if (j <= a[1]) dp[1][j] = 1;
		else break;
	}
	for (ll i = 2; i <= n; i++) dp[i][0] = dp[i - 1][0] * 2, dp[i][0] %= mod;
	for (ll i = 2; i <= n; i++) {
		for (ll j = 1; j <= 2 * maxn + 2; j++) {
			if (dp[i - 1][j] || a[i] >= j) { //可选可不选
				dp[i][j] = (dp[i - 1][j] % mod + dp[i - 1][max(0ll, j - a[i])] % mod) % mod;
			} else if (dp[i - 1][j - a[i]]) { //必选
				dp[i][j] = dp[i - 1][max(0ll, j - a[i])] % mod;
			} else break;//不可选
		}
	}
	for (ll i = 3; i <= n; i++) { //找最大
		ans += (dp[i][2 * a[i] + 1]-dp[i-1][2 * a[i]+1]) % mod;
		ans %= mod;
	}
	cout << ans % mod;
	return 0;
}