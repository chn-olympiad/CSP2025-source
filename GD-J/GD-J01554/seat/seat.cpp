#include<bits/stdc++.h>
using namespace std;
bool cmp(int x, int y) {
	return x>y;
}
int a[103];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout); 
	int n, m;
	cin >> n >> m;
	for (int i=1;i<=n*m;i++) {
		cin >> a[i];
	}
	int r=a[1];
	int ans;
	sort(a+1, a+n*m+1, cmp);
	for (int i=1;i<=n*m;i++) {
		if (a[i]==r) {
			ans=i;
			break;
		}
	}
	if (ans%n==0) {
		cout << ans/n << " ";
		if ((ans/n)%2) cout << n;
		else cout << 1;
	} else {
		cout << ans/n+1 << " ";
		if ((ans/n+1)%2) cout << ans%n;
		else cout << n-ans%n+1;
	}
	return 0;
}
