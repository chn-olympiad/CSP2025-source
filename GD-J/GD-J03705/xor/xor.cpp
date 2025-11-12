#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], b[500005];
struct Interval{
	int l, r;
};
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] ^= a[i - 1];
	}
//	for (int i = 1; i <= n; i++) {
//		cout << a[i] << " ";
//	}
//	cout << endl; 
	for (int i = 1; i <= n; i++)
		b[i] = a[i] ^ k;
//	for (int i = 1; i <= n; i++) {
//		cout << b[i] << " ";
//	}
//	puts("");
	// l = l - 1
	int ans = 0, lastt = 0;
	for (int r = 1; r <= n; r++) {
		for (int l = lastt; l < r; l++) {
			//cout << "ERR: " << l << " " << r << " " << a[l] << " " << b[r] << endl;
			if (b[r] == a[l]){
				//cout << "ERR: " << l + 1 << " " << r << endl;
				ans++;
				lastt = r;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
