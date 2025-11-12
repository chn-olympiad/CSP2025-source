#include <bits/stdc++.h>
using namespace std;
int n,ans,s,q;
int a[5005];
void dfs (int l,int maxn,int sum,int last) {
	if (last > n) return ;
	if (l >= 3 && sum > maxn * 2) {
		ans++;
		ans %= 998244353;
		return ;
	}
	for (int i = last + 1; i <= n; i++) {
		dfs(l + 1,max(maxn,a[i]),sum + a[i],i);
		dfs(l,maxn,sum,i);
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
		q = max(q,a[i]);
	}
	if (n < 3) {
		cout << 0;
		return 0;
	}
	if (n == 3) {
		if (a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1]) {
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	}
     dfs(0,0,0,0);
     if (q * 2 < s) ans++;
	cout << ans / 2;
	return 0;
} 
