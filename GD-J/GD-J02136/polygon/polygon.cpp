#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,M=1e4+5,mod=998244353;
#define int long long
int n,a[N],ans;
int f[N][M],sum[M];
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	freopen("A.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n); 
	f[1][0]=1;
	for(int i=2;i<=n;i++) {
		for(int j=0;j<=M-4;j++) {
			int t=j+a[i-1];
			t=min(t,M-4ll);
			f[i][j]=(f[i][j]+f[i-1][j])%mod;
			f[i][t]=(f[i][t]+f[i-1][j])%mod;
		} 
//		for(int j=0;j<=M-4;j++) cout<<f[i][j]<<" ";
//		cout<<endl;
		for(int j=M-4;j>=0;j--) sum[j]=(sum[j+1]+f[i][j])%mod; 
//		cout<<sum[a[i]+1]<<" ";
		ans=(ans+sum[a[i]+1])%mod;
	}
	cout<<ans;
	return 0;
}
