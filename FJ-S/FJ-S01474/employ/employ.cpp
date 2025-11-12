// Genshin Impact Start!!
// I'm too vegetable to work out the problem()
//freopen("employ.in","r",stdin);
// Keqing is so beutiful,is't she?
/*
I believe I could successfully enter NOIP.
it's my first time to take part in NOIP as a senior high school student.
However after a year's hard training,I didn't know whether
my ability for solving problem have been improved,
which depress me and make me fell uncertain for the future and unconfident for meself.
What's wrong?
Just enjoy a nice time coding and say goodbye to all of the trouble after NOIP. 
Will I win?
Probebly.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 505;

int n,m;
char s[N];
int c[N];
namespace A {
	bool vis[N];
	int ans,pr[N];
	bool check () {
		int cnt = 0;
		for (int i = 1;i <= n;i++) 
			if (cnt >= c[pr[i]] || s[i] == '0') cnt++;
		return n-cnt >= m;
	}
	void dfs (int p) {
		if (p > n) {
			if (check()) ans++;
			return;
		}
		for (int i = 1;i <= n;i++) {
			if (vis[i]) continue;
			vis[i] = 1;
			pr[p] = i;
			dfs(p+1);
			vis[i] = 0;
		}
	}
	void solve () {
		dfs(1);
		printf("%d\n",ans);
	}
}

namespace D {
	bool vis[N];
	int ans,pr[N];
	void dfs (int p,int cnt) {
		if (cnt > n-m) return;
		if (p > n) {
			if (cnt <= n-m) ans++;
			return;
		}
		for (int i = 1;i <= n;i++) {
			if (vis[i]) continue;
			vis[i] = 1;
			pr[p] = i;
			dfs(p+1,cnt + ((cnt >= c[pr[p]])|| s[p] == '0'));
			vis[i] = 0;
		}
	}
	void solve () {
		dfs(1,0);
		printf("%d\n",ans);
	}
}

//const int mod = 998244353;
//typedef long long ll;
//namespace B {
//	int f[(1<<18)+5][20];
//	bool vis[N];
//	int ans,pr[N];
//	int dfs (int p,int cnt,int sit) {
//		if (p > n && cnt <= n-m) return 1;
//		if (cnt > n-m) return 0;
//		if (f[sit][cnt]) return f[sit][cnt];
//		for (int i = 1;i <= n;i++) {
//			if (vis[i]) continue;
//			vis[i] = 1;
//			pr[p] = i;
//			int tmp = sit;
//			sit |= (1<<(i-1));
//			f[sit][cnt] += dfs(p+1,cnt + ((cnt >= c[i])|| s[p] == '0'),sit);
//			sit = tmp;
//			vis[i] = 0;
//		}
//		return f[sit][cnt];
//	}
//	void solve () {
//		for (int i = 0;i <= n-m;i++) f[(1<<n)-1][i] = 1;
//		printf("%d",dfs(1,0,0)%mod);
//	}
//}
//namespace C {
//	bool check () {
//		for (int i = 1;i <= n;i++) if (s[i] == '0') return 0;
//		return 1;
//	}
//	void solve () {
//		ll ans = 1;
//		for (int i = 1;i <= n;i++) 
//			ans = 1ll * ans * i % mod;
//		printf("%lld\n",ans);
//	}
//}
int main () {
	//freopen("employ2.in","r",stdin);
	//freopen("employ.out","w",stdout);	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i = 1;i <= n;i++) 
		scanf("%d",&c[i]);
	//sort(c+1,c+n+1);
	if (n <= 10) {
		A::solve();
	//	return 0;
	}
	D::solve();
//	if (C::check()) {
//		C::solve();
//		return 0;
//	}
	return 0;	
}
