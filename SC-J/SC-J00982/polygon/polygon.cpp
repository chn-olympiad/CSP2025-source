#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int a[5010];
long long ans = 0;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 3; i <= n; i++){
		for(int j = 1; j <= n - i + 1; j++){
			int maxx = max(max(a[j], a[j + 1]), a[j + 1]);
			if(a[j] + a[j + 1] + a[j + 2] > (2 * maxx)){
				ans++;
			}
		}
	}
	cout << ans % MOD << endl;
	return 0;
}