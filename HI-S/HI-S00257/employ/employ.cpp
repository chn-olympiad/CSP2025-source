#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s[505],c[505],ans,cnt1,cnt2;
bool flag;
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++) {
		cin>>s[i];
		if(s[i] != 1) flag = 1;
	}
	for(int i = 1; i <= n; i++) cin>>c[i];
	if(!flag) {
		ans = 1;
		for(int i = 0; i < n; i++) ans *= (n-i);
		cout<<ans;
		return 0;
	} else {
		sort(c+1,c+n+1);
		for(int i = 1; i <= n; i++) {
			ans += c[i];
		}
		cout<<ans;
	}
	return 0;
}
