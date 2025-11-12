#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n,a[5001],cnt;
void solve1(){//n <= 3
	if (n <= 2){
		cout << "0" << "\n";
		exit(0);
	}
	sort(a + 1,a + n + 1);
	if (a[1] + a[2] + a[3] > a[n] * 2){
		cout << 1 << "\n";
	}else{
		cout << 0 << "\n";
	}
	exit(0);
}
int jc(int x){
	if (x == 0){
		return 1;
	}
	return jc(x - 1) * x;
}
void solve2(){
	int ans = 0,nn = jc(n);
	for (int i = 3;i <= n;i++){
		ans = (ans + nn / (jc(i) * jc(n - i))) % mod;
//		cout << i << ":" << nn / (jc(i) * jc(n - i)) << "\n";
	}
	cout << ans << "\n";
	exit(0);
}
void dfs(int x,int sum,int zd){//准备选第x个数，之前个数为sum 
	if (x > n){
		return;
	}
	for (int i = zd + 1;i <= n;i++){
		if (a[i] + sum > a[i] * 2){
			cnt = (cnt + 1) % mod;
		}
		dfs(x + 1,sum + a[i],i);
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	bool b = true;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		if (a[i] > 1){
			b = false;
		}
	}
	sort(a + 1,a + n + 1);
	if (n <= 3){
		solve1();
	}
	if (b){
		solve2();
	}
	for (int i = 1;i <= n;i++){
		for (int j = i + 1;j <= n;j++){
			dfs(3,a[i] + a[j],j);
		}
	}
	cout << cnt << "\n";
	return 0;
}
/*
5
2 2 3 8 10
*/