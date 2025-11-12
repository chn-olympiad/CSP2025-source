#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5010],sum[5010],ans;
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	stable_sort(a+1,a+n+1);
	if(n<=3) {
		if(a[3]*2<(a[1]+a[2]+a[3])) {
			cout<<1;
		} else {
			cout<<0;
		}
		return 0;
	}
	int f[n+10][n+10],c[n+10][n+10];
	memset(f,0,sizeof(f));
	memset(c,0,sizeof(c));
	for(int i=1; i<=n; i++) {
		f[0][i]=f[i][0]=1;
		for(int j=1; j<=i; j++) {
			f[i][j]=f[i-1][j]+f[i-1][j-1];
			f[i][j]%=mod;
		}
	}
	for(int i=1; i<=n; i++) {
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=3; i<=n; i++) {
		for(int j=3; j<=i; j++) {
			c[i][j]=c[i-1][j];
			int s=a[i]*2,id=0;
			for(int k=1; k<=i; k++) {
				if(sum[k]>s) {
					id=k;
					break;
				}
			}
			c[i][j]+=f[i][id];
			c[i][j]%=mod;
		}
	}
	for(int i=3; i<=n; i++) {
		ans+=(f[n][i]-c[n][i]);
		ans%=mod;
	}
	cout<<ans;
}
