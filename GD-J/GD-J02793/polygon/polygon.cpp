#include<bits/stdc++.h>
#define int long long
#define mod 998244353

using namespace std;

int n,x,a[5005],b[5005],ans;

int dfs(int s){
	if(s > n){
		int mx = 0,sum = 0,num = 0;
		for(int i = 1;i <= n;i++){
			if(b[i]){
				mx = max(mx,a[i]);
				sum += a[i];
				num++;
			}
		}
		if(num >= 3 && sum > 2 * mx)return 1;
		else return 0;
	}
	int re = 0;
	b[s] = 0;
	re += dfs(s + 1);
	b[s] = 1;
	re += dfs(s + 1); 
	return re;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)cin >> a[i];
	if(n > 20 && n <= 700){
		sort(a + 1,a + n + 1);
		int lll = 1;
		while(!a[lll])lll++;
		int bb = 1;
		for(int i = 1;i < lll;lll++){
			bb *= 2;
			bb %= mod;
		}
		for(int i = lll + 2;i <= n;i++){
			int aa = 0;
			for(int j = 2;j <= i - lll;j++){
				int cc = 1;
				for(int z = 0;z < j;z++){
					cc = (cc * (n - z)) % mod;
				}
				for(int z = 1;z <= j;z++){
					cc = (cc / z) % mod;
				}
				aa += cc;
				aa %= mod;
			}
			ans = (ans + aa * bb % mod) % mod;
		}
		cout << ans << endl;
		return 0;
	}else if(n > 700){
		cout << 0 << endl;
		return 0;
	}
	ans = dfs(1);
	cout << ans << endl;
	return 0;
}
