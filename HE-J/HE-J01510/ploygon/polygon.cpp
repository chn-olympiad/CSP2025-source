#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,a[2100000],ans,s=1;
int jc(int n) {
	int s=1;
	for(int i=1; i<=n; i++) {
		s*=i;
		s%=998244353;
	}
	return s;
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=3) {
		if(a[1]+a[2]<=a[3]) {
			cout<<0;
		} else {
			cout<<1;
		}
	} else {
		for(int i=3; i<n; i++) {
			s+=(jc(n)/(jc(n-i)*jc(i)));
			s%=998244353;
		}
		cout<<s%998244353;
	}
	return 0;
}
