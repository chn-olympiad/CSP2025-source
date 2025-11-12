#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e18;

void solve(){
	int n;
	scanf("%d", &n);
	vector <array <int, 3> > a(n+1);
	vector <array <int, 2>> t1(n+1), t2(n+1), t3(n+1);
	bool A = true, B = true;
	for (int i = 1; i <= n; i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if (y != 0 || z != 0) A = false;
		if (z != 0) B = false;
		a[i] = {x, y, z};
		int w1, w2, w3;
		w1 = max(x, max(y, z));
		w2 = min(x, min(y, z));
		w3 = (x+y+z) - (w1+w2);
		if (x == w1){
			if (y == w2){
				t1[i] = {w1, 1};
				t2[i] = {w2, 2};
				t3[i] = {w3, 3};
			}else{
				t1[i] = {w1, 1};
				t2[i] = {w2, 3};
				t3[i] = {w3, 2};
			}
		}else if (y == w1){
			if (x == w2){
				t1[i] = {w1, 2};
				t2[i] = {w2, 1};
				t3[i] = {w3, 3};
			}else{
				t1[i] = {w1, 2};
				t2[i] = {w2, 3};
				t3[i] = {w3, 1};
			}
		}else{
			if (x == w2){
				t1[i] = {w1, 3};
				t2[i] = {w2, 1};
				t3[i] = {w3, 2};
			}else{
				t1[i] = {w1, 3};
				t2[i] = {w2, 2};
				t3[i] = {w3, 1};
			}
		}
	}
	if (A){
		sort(a.begin(), a.end());
		// for (auto [x, y, z] : a){
		// 	printf("%d %d %d\n", x, y, z);
		// }printf("\n");
		long long ans = 0;
		for (int i = n; i >= n/2+1; i--){
			ans += a[i][0];
		}printf("%lld\n", ans);
		return ;
	}
	sort(t1.begin()+1, t1.end());
	sort(t2.begin()+1, t2.end());
	sort(t3.begin()+1, t3.end());
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int _;
	scanf("%d", &_);
	while (_--) solve();
	return 0;
}