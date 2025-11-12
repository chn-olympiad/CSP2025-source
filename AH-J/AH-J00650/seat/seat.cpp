#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
bool cmp(int a, int b) {
	return a>b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n*m; i++) cin >> a[i];
	int ansh, ansl, ans;
	ans=a[0];
	sort(a, a+n*m, cmp);
	int cnt=lower_bound(a, a+n*m, ans, cmp)-a;
	ansl=cnt/n;
	if (ansl%2==0) {
		ansh=cnt%n;
		cout << ansl+1 << ' ' << ansh+1;
	} else if (ansl%2==1) {
		ansh=n-cnt%n;
		cout << ansl+1 << ' ' << ansh;
	}
	return 0;
}
