#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int M = 998244353, N = 5005;

int n,a[N],f[N][N],ans;

int ksm(int k) {
	if(k==0) return 1;
	int x = ksm(k/2);
	if(k&1) return (x*x*2) % M;
	else return (x*x) % M;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	int mx = -1;
	for(int i=1;i<=n;++i) {
		cin>>a[i];
		if(a[i]>mx) mx = a[i];
	}
	sort(a+1, a+1+n);
	f[0][0] = 1;
	for(int i=1;i<=n;++i) {
		for(int j=0;j<=mx;++j) f[i][j] = f[i-1][j];
		for(int j=mx;j>=a[i];--j) {
			if(f[i-1][j-a[i]]) (f[i][j] += f[i-1][j-a[i]]) %= M;
		}
	}
	for(int i=n,jq;i>=3;--i) {
		jq = 0;
		for(int j=0;j<=a[i];++j) (jq+=f[i-1][j]) %= M;
		ans += (ksm(i-1) + M - jq) % M;
	}
	cout<<ans;
	return 0;
}