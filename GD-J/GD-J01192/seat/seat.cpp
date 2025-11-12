#include <bits/stdc++.h>
using namespace std;
int f[105];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++){
		cin >> f[i];
	}
	int xiaor = f[0];
	sort(f, f + n * m);
	int l = 0, r = n * m - 1, ans = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (f[mid] == xiaor) {
			ans = mid;
			break;
		} else if (f[mid] > xiaor) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
		// cout << ans << " " << l << " " << r << " " << mid << endl;
	}
	// cout << ans << " " << f[ans] << endl;
	ans = n * m - ans;
	int lei = ans / n;
	int hang = ans % n;
	if (hang == 0) {
		hang = n;
	} else {
		lei++;
	}
	if (lei % 2 == 0) {
		hang = n - hang + 1;
	}
	cout << lei << " " << hang;
	return 0;
} 
