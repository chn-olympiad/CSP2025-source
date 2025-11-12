#include <iostream>
#include <vector>

using namespace std;

const int N = 5e5 + 5;

struct q
{
	int l;
	int r;
	int sum;
};

int n, m, lst;
bool sa, sb;
int a[N], vis[N];
int xorsum;
long long ans, cnt;
vector <q> v;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	sa = true, sb = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) {
			sa = false;
		}
		if (a[i] != 1 || a[i] != 0) {
			sb = false;
		}
	} 
	
	if (sa) { // 特殊性质 A 
		for (int i = 2; i <= n; i += 2) {
			ans += (n - i + 1);
		}
		
		cout << ans;
		return 0;
	}
	
	if (sb) { // 特殊性质 B 
		if (m == 0) {
			for (int i = 1; i <= n; i++) {
				if (a[i] == 0) ans++;
			}
			
			for (int i = 1; i <= n; i++) {
				if (cnt == 2) {
					ans++;
					cnt = 0;
				}
				
				if (a[i] == 1) {
					cnt++;	
				}
			}
			
			if (cnt == 2) ans++;
 			
			cout << ans;
			
			return 0;
		} else {
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1) ans++;
			}
			
			cout << ans;
			return 0;
		}
	}
	
	// 无特殊性质
	
	// 区间
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			xorsum = 0;
			for (int k = i; k <= j; k++) {
				xorsum ^= a[k];
				
				if (vis[k] < (j - i + 1) && vis[k] != 0) {
//					cout << i << " " << j << " " << k << " " << vis[k] << endl;
					xorsum = -1;
					break;
				}
			}
			
			if (xorsum == m) {
//				cout << i << " " << j << " " << xorsum << '\n'; 
				ans++;
				lst = vis[i];
				for (int k = i; k <= j; k++) {
					if (vis[k] != 0) {
						int t = vis[k];
						for (int kk = k; vis[kk] == t; kk++) {
//							cout << "	" << kk << " " << vis[kk] << " " << vis[kk + 1] << endl;
							vis[kk] = 0;
						}
						ans--;
					}
//					cout << "-- " << ans << " " << i << " " << j << " " << vis[k] << " " <<	vis[k - 1] << " " << k << '\n';
					vis[k] = (j - i + 1);
				}
			} 
		}
	}
	
	cout << ans;
	
	return 0;
}
// AC this!
// And AK CSP!