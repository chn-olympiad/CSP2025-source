#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,a[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	if (n == 3){
		if (a[1] + a[2] > a[3]) cout << 1;
		else cout << 0;
	}
	if (n == 4){
		if (a[1] + a[2] > a[3]) ans++;
		if (a[1] + a[2] > a[4]) ans++;
		if (a[2] + a[3] > a[4]) ans++;
		if (a[1] + a[2] + a[3] > a[4]) ans++;
		cout << ans;
	}
	if (n == 5){
		if (a[1] + a[2] > a[3]) ans++;
		if (a[1] + a[2] > a[4]) ans++;
		if (a[1] + a[2] > a[5]) ans++;
		if (a[1] + a[3] > a[4]) ans++;
		if (a[1] + a[3] > a[5]) ans++;
		if (a[1] + a[4] > a[5]) ans++;
		if (a[1] + a[2] + a[3] > a[4]) ans++;
		if (a[1] + a[2] + a[3] > a[5]) ans++;
		if (a[1] + a[2] + a[4] > a[5]) ans++;
		if (a[1] + a[3] + a[4] > a[5]) ans++;
		if (a[2] + a[3] + a[4] > a[5]) ans++;
		if (a[1] + a[2] + a[3] + a[4] > a[5]) ans++;
		cout << ans;
	}
	return 0;
}
