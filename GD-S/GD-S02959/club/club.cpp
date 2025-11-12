#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;

ll t;
int main() {
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	
	cin >> t;
	
	while (t--) {
		ll n, aop = 0, bop = 0, cop = 0, sum = 0, mx = 0, pvp = 0;
		cin >> n;
		
		ll fz = n / 2;
		for (ll i = 1; i <= n; i++) {
			ll a, b, c;
			cin >> a >> b >> c;
			
			ll maxx = max(a, max(b, c));
			mx = max(mx, maxx);
			ll minn = min(a, min(b, c));
			ll sec = a + b + c - maxx - minn;
			
			if (mx == maxx && fz >= aop - 1) sum += mx - b;
			
			if (fz >= aop) {
				if (mx != maxx) b = maxx, sum += maxx, aop++;
				else sum += maxx, aop++;
		}
			else if (fz >= bop) sum += sec, bop++;
			else sum += minn, cop++;
			
		}
		cout << sum << endl;
	}
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
