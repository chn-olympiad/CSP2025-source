#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, a[N][3], b[N][2], x[N], y[N], z[N], cnt1, cnt2, cnt3;
long long ans;

bool cmp(int i, int j){
	return b[i][0] - b[i][1] > b[j][0] - b[j][1];
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> T;
	
	while (T--){
		ans = cnt1 = cnt2 = cnt3 = 0;
		
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			
//			if (a[i][0] > a[i][1] > a[i][2])
//				b[i][0] = a[i][0], b[i][1] = a[i][1], x[++cnt1] = i;
//			else if (a[i][0] >= a[i][2] > a[i][1])
//				b[i][0] = a[i][0], b[i][1] = a[i][2], x[++cnt1] = i;
//			else if (a[i][1] > a[i][0] > a[i][2])
//				b[i][0] = a[i][1], b[i][1] = a[i][0], y[++cnt2] = i;
//			else if (a[i][1] > a[i][2] > a[i][0])
//				b[i][0] = a[i][1], b[i][1] = a[i][2], y[++cnt2] = i;
//			else if (a[i][2] > a[i][0] > a[i][1])
//				b[i][0] = a[i][2], b[i][1] = a[i][0], z[++cnt3] = i;
//			else 
//				b[i][0] = a[i][2], b[i][1] = a[i][1], z[++cnt3] = i;

			if (a[i][0] >= a[i][1] && a[i][1] >= a[i][2])
				b[i][0] = a[i][0], b[i][1] = a[i][1], x[++cnt1] = i;
			else if (a[i][0] >= a[i][2] && a[i][2] >= a[i][1])
				b[i][0] = a[i][0], b[i][1] = a[i][2], x[++cnt1] = i;
			else if (a[i][1] >= a[i][0] && a[i][0] >= a[i][2])
				b[i][0] = a[i][1], b[i][1] = a[i][0], y[++cnt2] = i;
			else if (a[i][1] >= a[i][2] && a[i][2] >= a[i][0])
				b[i][0] = a[i][1], b[i][1] = a[i][2], y[++cnt2] = i;
			else if (a[i][2] >= a[i][0] && a[i][0] >= a[i][1])
				b[i][0] = a[i][2], b[i][1] = a[i][0], z[++cnt3] = i;
			else 
				b[i][0] = a[i][2], b[i][1] = a[i][1], z[++cnt3] = i;
				
		}
		
//		for (int i = 1; i <= n; i++)
//			cout << b[i][0] << ' ' << b[i][1] << '\n';
//		cout << '\n';
//		for (int i = cnt1; i <= cnt1; i++)
//			cout << x[i];
//		cout << '\n';
//		for (int i = cnt2; i <= cnt2; i++)
//			cout << y[i];
//		cout << '\n';
//		for (int i = cnt3; i <= cnt3; i++)
//			cout << z[i];
//		cout << '\n';
		
		if (cnt1 <= n / 2){
			for (int i = 1; i <= cnt1; i++)
				ans += b[ x[i] ][0];
		} else{
			sort(x + 1, x + cnt1 + 1, cmp);
			for (int i = 1; i <= n / 2; i++)
				ans += b[ x[i] ][0];
			for (int i = n / 2 + 1; i <= cnt1; i++)
				ans += b[ x[i] ][1];
		}
		
		if (cnt2 <= n / 2){
			for (int i = 1; i <= cnt2; i++)
				ans += b[ y[i] ][0];
		} else{
			sort(y + 1, y + cnt2 + 1, cmp);
			for (int i = 1; i <= n / 2; i++)
				ans += b[ y[i] ][0];
			for (int i = n / 2 + 1; i <= cnt2; i++)
				ans += b[ y[i] ][1];
		}
		
		if (cnt3 <= n / 2){
			for (int i = 1; i <= cnt3; i++)
				ans += b[ z[i] ][0];
		} else{
			sort(z + 1, z + cnt3 + 1, cmp);
			for (int i = 1; i <= n / 2; i++)
				ans += b[ z[i] ][0];
			for (int i = n / 2 + 1; i <= cnt3; i++)
				ans += b[ z[i] ][1];
		}
		
		cout << ans << '\n';
	}
	return 0;
} 
