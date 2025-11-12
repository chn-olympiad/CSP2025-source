#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 300;
ll f[maxn][maxn][maxn];
ll a[maxn][3];
ll n;
ll b[maxn];
void init(){
	for(int i = 0 ; i < maxn ; i++){
		for(int j = 0 ; j < maxn ; j++){
			for(int k = 0 ; k < maxn ; k++){
				f[i][j][k] = 0;
			}
		}
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		init();
		int tmp = n / 2;
		bool flag= false;
		ll as = 0;
		for(int i = 1 ; i <= n ; i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			if(a[i][1] == a[i][2] && a[i][1] == 0)flag = true;
		}
		if(flag){
			for(int i = 1 ; i <= n ; i++){
				b[i] = a[i][0];
			}
			sort(b + 1, b + n + 1);
			for(int i = n ; i > n / 2 ; i--){
				as+= b[i];
			}
			cout << as << endl;
		}else{
		for(int i = 1 ; i <= n ; i++){
			for(int j = 0 ; j <= min(i, tmp) ; j++){
				for(int k = 0  ; k <= min(i, tmp) ; k++){
					if(i - j - k > n / 2)continue;
					if(j + k > i)break;
					if(j == 0 && k ==0){
						f[i][0][0] =  f[i - 1][0][0] + a[i][2];
					}else if(j == 0 && k == i){
						f[i][0][i] =  f[i - 1][0][i - 1] + a[i][1];
					}else if(j == i && k ==0){
						f[i][i][0] =  f[i - 1][i - 1][0] + a[i][0];
					}else if(i - j + k == 0){
						f[i][j][k] = max(f[i - 1][j - 1][k] + a[i][0],f[i - 1][j][k - 1] + a[i][1]);
					}else if(j == 0){
						f[i][0][k] =  max(f[i - 1][0][k] + a[i][2],f[i - 1][0][k - 1] + a[i][1]);
					}else if(k == 0){
						f[i][j][0] = max(f[i - 1][j - 1][0] + a[i][0], f[i - 1][j][0] + a[i][2]);
					}else f[i][j][k] = max(f[i - 1][j - 1][k] + a[i][0],max(f[i - 1][j][k] + a[i][2],f[i - 1][j][k - 1] + a[i][1]));
				}
			}
			}
		
		ll ans = -1;
		for(int j = 0 ; j <= n / 2 ; j++){
			for(int k = 0 ; k <= n / 2 ; k++){
				ans = max(ans, f[n][j][k]);
			}
		}
		cout << ans << endl;
		}
	}
	return 0;
}
