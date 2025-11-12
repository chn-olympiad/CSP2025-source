#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll M = 998244353;
const int N = 505;
int n, m, c[N];
ll ans;
string s;

int a[15], v[15], ps, f;
void dfs(int x) {
	if(x == n+1) {
		ps = f = 0;
		for(int i=1; i<=n; i++) {
			if(ps < c[a[i]] && s[i-1] == 49)
				++f;
			else ++ps;
		}
//		cout<<a[1]<<' '<<a[2]<<' '<<a[3]<<' '<<ps<<' '<<f<<' '<<endl;
		if(f >= m)  {
//			for(int i=1; i<=n; i++)
//				printf("%d ", a[i]);
//			puts("");
			ans = (ans+1)%M;
		}
		return ;
	}
	for(int i=1; i<=n; i++)
		if(!v[i]) {
			v[i] = 1;
			a[x] = i;
			dfs(x+1);
			v[i] = 0;
		}
}

//ll inv[N], fc[N];
//ll qp(ll x, ll y) {
//	ll ret = 1;
//	while(y) {
//		if(y&1) ret = ret*x%M;
//		x = x*x%M;
//		y >>= 1;
//	}
//	return ret;
//}
void whzz() {
	sort(c+1, c+1+n);
	for(int i=1; i<=n; i++)
		if(c[i] != 0) {
			f = i-1;
			break;
		}
	cout<<f<<endl;
	n -= f;
	if(n < m) {
		puts("0");
		return ;
	}
	ans = 1;
	for(int i=1; i<=n; i++)
		ans = ans*i%M;
	printf("%lld\n", ans);
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin>>s;
	for(int i=1; i<=n; i++)
		scanf("%d", &c[i]);
	if(n <= 10) {
		dfs(1);
		printf("%lld\n", ans);
		return 0;
	}
	whzz();
	return 0;
}
