#include <bits/stdc++.h>
#define endl '\n';
#define ll long long 
using namespace std;
ll n,m,a[500005],s[500005],ans;
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++) s[i]=s[i-1]^a[i];
	for(int i=1; i<=n; i++) {
		if(a[i]==0) continue;
		if(ans&&(!s[i]||s[i]==m)) ans++;
		else if(ans==0&&s[i]==m) ans++; 
	}
	cout << ans;
	return 0;
}
