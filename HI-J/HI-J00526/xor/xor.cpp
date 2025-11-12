#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],s[500005],cnt,ans,ma;
bool flag;
void solve() {
	for(int i = 1; i <= n; i++) {
		if(a[i] == 1&&a[i-1] == 1) {
			ans++;
			i++;
		} else if(a[i] == 0) ans++;
	}
	cout<<ans;
}
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i = 1; i <= n; i++) {
		cin>>a[i];
		s[i] = s[i-1] ^ a[i];
		ma = max(ma,a[i]);
		if(a[i] == 0) flag = 1;
		if(a[i] == 1) cnt++;
	}
	if(ma == 1&&!flag) {
		if(k == 0) cout<<n/2;
		else cout<<n;
	} else if(ma == 1&&flag) {
		if(k == 0) solve();
		else cout<<cnt;
	}
	return 0;
}
