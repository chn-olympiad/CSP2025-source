#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int N = 200 + 10, MAXN = 1e5 + 10;
int ans;
int n, a[MAXN][4];
int f[N][N];

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				cin >> a[i][j];
			}
		}
		memset(f, -0x3f, sizeof(f));
		f[0][0] = 0; 
		for(int i = 1; i <= n; i++){
			for(int k1 = n / 2; k1 >= 0; k1--){
				for(int k2 = n / 2; k2 >= 0; k2--){
					if(k1 + k2 > i) continue;
					int now = f[k1][k2];
					int k3 = i - k1 - k2;
					if(k3 > n / 2) continue;
					if(k1 > 0) f[k1][k2] = max(f[k1][k2], f[k1 - 1][k2] + a[i][1]);
					if(k2 > 0) f[k1][k2] = max(f[k1][k2], f[k1][k2 - 1] + a[i][2]);
					if(k3 > 0) f[k1][k2] = max(f[k1][k2], now + a[i][3]);
					if(i == n) ans = max(ans, f[k1][k2]);
				}
			}
		}
		cout << ans << "\n";
		ans = 0;
	}
	return 0;
}
