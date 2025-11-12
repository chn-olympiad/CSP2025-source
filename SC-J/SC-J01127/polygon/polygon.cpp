#include<bits/stdc++.h>
using namespace std;
const int maxn=5005,MOD=998244353;

long long n,a[maxn],ans;

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; ++i) cin>>a[i];
	sort(a,a+n+1);
	if(n==3) if(a[i]+a[i+1]>a[i+2]) ans++;
	else {
		if(a[i]+a[i+1]>a[i+2]) ans++;
		if(a[i]+a[i+1]>a[i+3]) ans++;
		if(a[i]+a[i+2]>a[i+3]) ans++;
		if(a[i+1]+a[i+2]>a[i+3]) ans++;
		if(a[i]+a[i+1]+a[i+2]>a[i+3]) ans++;
	}
	cout<<ans%MOD;
	return 0;
}