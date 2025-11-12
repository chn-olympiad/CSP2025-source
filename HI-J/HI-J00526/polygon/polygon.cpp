#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n,a[5005],s[5005],ma;
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i],ma = max(a[i],ma);
	sort(a+1,a+n+1);
	if(n <= 3) {
		if(a[1] + a[2] > a[3]) cout<<1;
		else cout<<0;
	}
	return 0;
}
