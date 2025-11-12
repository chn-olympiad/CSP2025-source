#include <bits/stdc++.h>
using namespace std;

int n,m;
int r,cnt = 1;
int an,am;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	cin >> r;
	for(int i = 2; i <= n * m; i ++) {
		int t;
		cin >> t;
		if (t > r) cnt++;
	}
	an = (cnt - 1) / n + 1;
	int mo = (cnt - 1) % n + 1;
	am = (an & 1) ? mo : m - mo + 1;
	cout << an << " "<< am;
}
