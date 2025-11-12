#include <bits/stdc++.h>


using namespace std;

const int N = 5e3 + 5;
const long long mod = 998244353;

int n,a[N],ans,sum,maxx;

int main () {

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	for (int i = 1;i <= n;i ++) {
		cin >> a[i];
		sum += a[i];
		maxx = max (maxx,a[i]);
	}

	if (n <= 3) {
		if (sum > maxx * 2) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	
	return 0;
}

