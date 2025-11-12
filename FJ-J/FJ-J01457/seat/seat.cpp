#include<bits/stdc++.h>
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;

const int NM = 1e2+5;
int n, m, a[NM];

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	IOS;
	cin >> n >> m;
	for(int i=1; i<=n * m; i++) {
		cin >> a[i];
	}
	int s = a[1], t=1;
	sort(a+1, a+n*m+1, cmp);
	for(int i=1; i<=m; i++) {
		if(i % 2 == 1) {
			for(int j=1; j<=n; j++, t++) {
				if(a[t] == s) {
					cout << i << " " << j << endl;
					return 0;
				}
			}
		} else {
			for(int j=n; j>=1; j--, t++) {
				if(a[t] == s) {
					cout << i << " " << j << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}

