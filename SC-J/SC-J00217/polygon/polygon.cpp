#include<bits/stdc++.h>
using namespace std;
int n, a[5010], u = 998244353, ans;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	if (n == 3){
		if (a[1]+a[2]+a[3] > a[3]*2) cout << "1";
		else cout << "0";
		return 0;
	}
	if (a[1]+a[2]+a[3]>a[3]*2 && n>=3) ans++;
	if (a[1]+a[2]+a[4]>a[4]*2 && n>=4) ans++;
	if (a[1]+a[2]+a[5]>a[5]*2 && n>=5) ans++;
	if (a[1]+a[3]+a[4]>a[4]*2 && n>=4) ans++;
	if (a[1]+a[3]+a[5]>a[5]*2 && n>=5) ans++;
	if (a[1]+a[4]+a[5]>a[5]*2 && n>=5) ans++;
	if (a[2]+a[3]+a[4]>a[4]*2 && n>=4) ans++;
	if (a[2]+a[3]+a[5]>a[5]*2 && n>=5) ans++;
	if (a[2]+a[4]+a[5]>a[5]*2 && n>=5) ans++;
	if (a[3]+a[4]+a[5]>a[5]*2 && n>=5) ans++;
	if (a[1]+a[2]+a[3]+a[4]>a[4]*2 && n>=4) ans++;
	if (a[1]+a[2]+a[3]+a[5]>a[5]*2 && n>=5) ans++;
	if (a[1]+a[2]+a[4]+a[5]>a[5]*2 && n>=5) ans++;
	if (a[1]+a[5]+a[3]+a[4]>a[5]*2 && n>=5) ans++;
	if (a[5]+a[2]+a[3]+a[4]>a[5]*2 && n>=5) ans++;
	if (a[1]+a[2]+a[3]+a[4]+a[5]>a[5]*2&&n>=5) ans++;
	cout << ans;
	return 0;
}