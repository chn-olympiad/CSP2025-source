#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int dp[N][22];
int n,k;
int a[N];
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	freopen("xor.in","r",stdin);
//	freopen("xor.ans","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	bool pd=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=1)pd=1;
//		zhuan(a[i],i);
	}
//	zhuan(k,n+1);
	if(pd==0&&k==1) {
		int num=0;
		for(int i=1; i<=n; i++) {
			if(a[i]==0)num++;
		}
		int ans=min(num,n-num);
		int nn=n;
		nn-=ans;
		if(num>=n-num)cout<<ans<<'\n';
		else cout<<ans+nn/3<<'\n';
		return 0;
	}
	if(k==0) {
		cout<<n<<'\n';
		return 0;
	}
	return 0;
}
