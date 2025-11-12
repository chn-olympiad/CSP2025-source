#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
int a[5005];
long long S_all = 0;
int main () {
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	
	scanf ("%d",&n);
	for (int i = 1;i <= n; ++i) {
		scanf ("%d",&a[i]);
		S_all += a[i];
	}
	sort (a + 1,a + n + 1);
	if (n < 3) {
		cout << 0;
		return 0;
	} 
	if (n == 3) {
		int cnt = 0;
		if (S_all > 2 * a[3]) cnt+=1;
		cout << cnt;
		return 0;
	}
	if (a[1] == a[n]) {
		cout << (n - 2) % mod;
		return 0;
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
