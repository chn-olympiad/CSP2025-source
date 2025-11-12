#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[505],dp[505][505],s[505],t[505],ans;
const ll M = 998244353;
int main() {
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		if (a[i] != 0) dp[1][1]++;
	}
	for (int i=0;i<s.size();i++) {
		s[i+1] = s[i];
		if (s[i] == '0') {
			s[i+1]++;
			for (int j=1;j<=n;j++) if (a[j]>s[i+1]) t[i+1]++;
		}
	}
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++) {
		for (int j=0;j<=n;j++) {
			dp[i][j] = dp[i-1][j-1]*t[i]%M;
		}
	}
	for (int i=m;i<=n;i++) ans+=dp[n][i];
	cout<<ans<<endl;
	return 0;
} 
