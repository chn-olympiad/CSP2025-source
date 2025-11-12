# include<bits/stdc++.h>
# define int long long
using namespace std;

const int N = 2e5+5,mod = 1e9+7,P = 13331;
int n,Q,fx[N],fy[N],f[N],g[N];
string a[N],b[N];
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> Q;
	for (int i = 1;i <= n;i++) {
		string x,y;
		cin >> x >> y;
		a[i] = x,b[i] = y;
		if (x == y) continue;
		int len = x.size();
		fx[i] = -1,fy[i] = len;
		for (int j = 0;j < len;j++) {
			if (x[j] != y[j]) break;
			else fx[i] = j;
		}
		for (int j = len-1;j >= 0;j--) {
			if (x[j] != y[j]) break;
			else fy[i] = j;
		}
		for (int j = fx[i]+1;j < fy[i];j++) f[i] = (P*f[i]%mod+x[j]-'a')%mod;
		for (int j = fx[i]+1;j < fy[i];j++) g[i] = (P*g[i]%mod+y[j]-'a')%mod;
	}
	while (Q--) {
		string x,y;
		cin >> x >> y;
		if (x.size() != y.size()) {
			cout << 0 << '\n';
			continue;
		}
		int len = x.size();
		int s = -1,e = len,sumx = 0,sumy = 0,ans = 0;
		for (int i = 0;i < len;i++) {
			if (x[i] != y[i]) break;
			else s = i;
		}
		for (int i = len-1;i >= 0;i--) {
			if (x[i] != y[i]) break;
			else e = i;
		}
		for (int i = s+1;i < e;i++) sumx = (sumx*P%mod+x[i]-'a')%mod;
		for (int i = s+1;i < e;i++) sumy = (sumy*P%mod+y[i]-'a')%mod;
		for (int i = 1;i <= n;i++) {
			if (sumx!=f[i] || sumy!=g[i]) continue;
			if (fx[i]>s || a[i].size()-fy[i]>len-e) continue;
			int flag = 1,tmp = a[i].size();
			for (int j = 0;j < tmp;j++) {
				if (a[i][j] != x[j+s-fx[i]]) {
					flag = 0;
					break;
				}
			}
			ans += flag;
		}
		cout << ans << '\n';
	}
	
	return 0;
}
