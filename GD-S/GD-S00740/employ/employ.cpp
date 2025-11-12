# include<bits/stdc++.h>
# define int long long
using namespace std;

const int N = 505;
int n,m,a[N],b[N],s[N],g[N],cnt;
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i],s[i] = s[i-1]+a[i];
		if (a[i]) g[++cnt] = i;
	}
	for (int i = 1;i <= m;i++) cin >> b[i];
	
	return 0;
}
