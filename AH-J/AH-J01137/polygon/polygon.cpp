#include <bits/stdc++.h>
#define endl '\n';
#define ll long long 
using namespace std;
ll n,a[5005],sum;
ll C(int x) {
	int s2=1,s1=1;
	for(int i=n; i>=n-x+1; i--) {
		s2=(s2*i)%998244353;
	}
	for(int i=x; i>=1; i--) {
		s1=(s1*i)%998244353;
	}
	return (s2/s1)%998244353;
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=3; i<=n; i++) sum=(sum+C(i))%998244353;
	cout << sum;
	return 0;
}
