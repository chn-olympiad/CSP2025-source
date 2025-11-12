#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5005][5005];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==3) {
		int a[5];
		cin>>a[1]>>a[2]>>a[3];
		sort(a+1,a+4);
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	} else {
		int ans=0;
		for(int i=0; i<=n+1; ++i) {
			a[i][0]=a[i][i]=1;
			for(int j=0; j<i; ++j)
				a[i][j]=(a[i-1][j]+a[i-1][j-1])%mod;
		}
		for(int i=3; i<=n+1; ++i) ans=(ans+a[n][i])%mod;
		cout<<ans;
	}
	return 0;
}