#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

const ll P = 998244353;
const int MXN = 5e3 + 5;
const int OVR = 5e3 + 1;
ll d[MXN][4], ans; 
int n, mxa, a[MXN];

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i += 1){
		cin >> a[i];
		mxa = max(mxa, a[i]);
	}
	if (mxa == 1){
		ans = 1;
		for (int i = 1; i <= n; i += 1) ans = (ans << 1) % P;
		ans = (ans + P - n * (n - 1) / 2 - n - 1) % P;
		cout << ans;
		return 0;
	}
	sort(a + 1, a + n + 1);
	
	d[0][0] = 1;
	for (int i = 1; i <= n; i += 1){
		for (int j = OVR; j >= 0; j -= 1){
			for (int k = 3; k >= 0; k -= 1){
				d[min(j + a[i], OVR)][min(k + 1, 3)] += d[j][k];
				if (j > a[i]) ans += d[j][k];
				ans %= P; d[min(j + a[i], OVR)][min(k + 1, 3)] %= P;
			}
		}
	}
	
	cout << ans;
	return 0;
}
