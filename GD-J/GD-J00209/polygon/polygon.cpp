#include<iostream>
#include<algorithm> 
using namespace std;
const int mod = 998244353;

int n, ans;
int a[5005], vis[5005];

void dfs(int p, int maxa, int choose){
	if (p > n){
		if (choose >= 3){
			int sum = 0;
			for (int i = 1; i <= n; i++){
				if (vis[i]) sum += a[i];
			}
			if (sum > 2*maxa) ans++;
			ans %= mod;
		}
		return ;
	}
	
	vis[p] = 0;
	dfs(p+1, maxa, choose);
	vis[p] = 1;
	dfs(p+1, a[p], choose+1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
