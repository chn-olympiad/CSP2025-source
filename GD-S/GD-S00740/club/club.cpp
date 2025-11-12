# include<bits/stdc++.h>
# define int long long
using namespace std;

const int N = 1e5+5;
int T,n,x[N],y[N],z[N],ans,f[N];
vector<int> a,b,c;
int cmp(int x,int y) {
	return f[x] < f[y];
}
void upd() {
	sort(a.begin(),a.end(),cmp);
	int len = a.size();
	for (int i = 0;i < len-n/2;i++) ans -= f[a[i]];	
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		a.clear(),b.clear(),c.clear(),ans = 0;
		for (int i = 1;i <= n;i++) {
			cin >> x[i] >> y[i] >> z[i];
			int maxx = max(max(x[i],y[i]),z[i]);
			ans += maxx;
			if (x[i] == maxx) a.push_back(i),f[i] = x[i]-max(y[i],z[i]);
			else if (y[i] == maxx) b.push_back(i),f[i] = y[i]-max(x[i],z[i]);
			else c.push_back(i),f[i] = z[i]-max(x[i],y[i]);
		}
		if (a.size() > n/2) upd();
		else if (b.size() > n/2) swap(a,b),upd();
		else if (c.size() > n/2) swap(a,c),upd();
		cout << ans << '\n';
	}
	
	return 0;
} 
