
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n;
const int N = 5000 + 5;
int a[N],f[N],ans;
inline bool check(int d) {
	if(d<3) return false;
	int sum=0,mx = INT_MIN;
	//cout << "checking-d=" << d << ": ";
	for(int i=1; i<=d; i++) {
		sum += f[i];
		mx = max(mx,f[i]);
		//cout << f[i] << ' ';
	}
	//cout << " | sum=" << sum << ",mx=" << mx << '|'<< (sum>mx*2) << endl;
	if(sum>mx*2) return true;
	else return false;
}
inline void dfs(int d, int x) {//write in f[d]
	//check f
	if(check(d-1)) {
		ans ++;
		ans %= 998244353;
	}
	if(d>n+1||x>n) return ;
	//choose next number
	for(int i=x; i<=n; i++) {
		f[d] = a[i];
		dfs(d+1,i+1);
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	dfs(1,1);
	cout << ans << endl;
	return 0;
}
