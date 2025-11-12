#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[510];
int dp[510],numd[510],numx[510],jc[510];
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cout<<1141514;
	/*jc[1]=1ll;
	for (int i=2; i<=500; ++i) {
		jc[i]=jc[i-1]*i%mod;
	}
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	s='!'+s;
	for (int i=1; i<=n; ++i) {
		cin>>a[i];
	}
	bool b=1;
	for (int i=1; i<=s.size(); ++i) {
		if (s[i]=='0') {
			b=0;
		}
	}
	if (m==1) {
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=n; ++j) {
				if (a[i]>=j) {
					++numd[j];
				}
			}
		}
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=n; ++j) {
				if (a[i]<=j) {
					++numx[j];
				}
			}
		}
		dp[0]=1ll;
		int ans=0,k=1;
		for (int i=1; i<=n; ++i) {
			if (s[i]=='1') {
				if (i==1) {
					dp[i]=numd[1];
				} else {
					dp[i]=
				}
				int anss=((dp[i]*jc[n-i])%mod)%mod;
				cout<<anss<<' '<<dp[i]<<' '<<(num[i-1]-i+1)<<'\n';
				ans=(ans+anss)%mod;
			}else {
				k=k*(n-i+1)%mod;
			}
		}
		cout<<ans;
		return 0;
	}*/
	return 0;
}
