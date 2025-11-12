#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5,mod = 998244353;
int n,m,a[N],c[N];
bool flg = 1;
string s;
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> s ;
	for(int i=1;i<=n;i++) {
		cin >> c[i],a[i] = i;
	}
	for(int i=0;i<n;i++) flg = flg && (s[i]=='1');
	if(n<=10) {
		int cnt = 0;
		do{
			int cs = 0,ds = 0;
			for(int i=1;i<=n;i++) {
				// if(c[a[i]]<=ds) continue;
				if(s[i-1]=='1'&&c[a[i]]>ds) cs++;
				else ds++;
			}
			// if(cs>=m)for(int i=1;i<=n;i++) cout << a[i] << " ",cout<<"\n";
			if(cs>=m) cnt++;
		}while(next_permutation(a+1,a+n+1));
		cout << cnt << "\n";
	}
	else if(m==n) {
		if(flg==0) cout << 0 << "\n";
		else {
			int rs = 1;
			for(int i=1;i<=n;i++) {
				rs = rs * i;
				rs %= mod;
			}
			cout << rs << "\n";
		}
	}
	else cout << 0 << "\n";
	return 0;
}