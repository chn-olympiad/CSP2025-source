#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
#define pii pair<int, int>
#define se second
#define fi first
#define ll long long
int n, siz[4];
ll ans;
pii a[N][4];
vector<int> vec;
void solve(){
	scanf("%d", &n);
	ans = 0;
	vec.clear();
	for(int i = 1; i <= 3; i++) siz[i] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 3; j++){
			scanf("%d", &a[i][j].fi);
			a[i][j].se = j;
		}
		for(int j = 1; j <= 3; j++){
			for(int k = j; k <= 3; k++){
				if(a[i][j] < a[i][k]){
					swap(a[i][j], a[i][k]);
				}
			}
		}
		siz[a[i][1].se]++;
		ans += a[i][1].fi;
	}
	int num = 0;
	for(int i = 1; i <= 3; i++){
		if(siz[i] > n / 2){
			num = siz[i] - (n / 2);
			for(int j = 1; j <= n; j++){
				if(a[j][1].se == i){
					vec.push_back(a[j][1].fi - a[j][2].fi);
				}
			}
		}	
	}
	sort(vec.begin(), vec.end());
	for(auto v : vec){
		if(num == 0) break;
		num--;
		ans -= v;
	}
	printf("%lld\n", ans);
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);	
	int T;
	scanf("%d", &T);
	while(T--) solve();
}
