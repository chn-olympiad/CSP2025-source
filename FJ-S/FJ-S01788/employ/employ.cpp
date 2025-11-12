#include<bits/stdc++.h>
using namespace std;
int n,m,k;
char a[1000];
long long jiechen(int n) {
	long long ans=1;
	for(int i=1; i<=n; i++) {
		ans*=i;
		ans%=998244353;
	}
	return ans;
}
int main() {
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]=='0') {
			cout<<0;
			return 0;
		}
	}
	cout<<jiechen(n);
	return 0;
}


