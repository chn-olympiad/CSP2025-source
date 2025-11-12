#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505,mod = 998244353;
int n,m,a[N],flg = 1,cnt0,fc[N],p[N],flag[N],res;
string s;
int c[N];
void dfs(int x){
	if (x > n){
		int cnt = 0,fail = 0;
		for (int i = 1;i <= n;i++){
			if (!a[i] || fail >= c[p[i]])fail++;
			else cnt++;
		}
		res += (cnt >= m);
		return ;
	}
	for (int i = 1;i <= n;i++){
		if (flag[i]) continue;
		p[x] = i;
		flag[i] = 1;
		dfs(x + 1);
		flag[i] = 0;
	}
}
void solve1(){
	res = 0;
	dfs(1);
	cout << res % mod << '\n';
}
void solve2(){
	res = 1;
	for (int i = 1;i <= n;i++){
		int pos = upper_bound(c + 1,c + n + 1,i-1) - c - 1;
		if (pos < i){
			res = -1;
			break;
		}else{
			res = res * (pos - i + 1) % mod;
		}
	}
	if (res == -1) cout << "0\n";
	else cout << ((fc[n] - res) % mod + mod) % mod << '\n';
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	cin >> s;
	fc[0] = 1;
	for (int i = 1;i <= n;i++){
		a[i] = s[i-1] - '0';
		if (!a[i]) flg = 0;
		fc[i] = fc[i-1] * i % mod;
	}
	for (int i = 1;i <= n;i++){
		cin >> c[i];
		cnt0 += (c[i] == 0);
	}
	sort(c+1,c+n+1);
	if (n <= 10){
		solve1();
		return 0;
	}
	if (m == 1){
		solve2();
		return 0;
	}
 	if (n - cnt0 < m) cout << "0\n";
 	else cout << fc[n-cnt0] << '\n';
	return 0;
}












