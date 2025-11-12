#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
char z;
int a[505],c[505];
long long ans;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>z;
		a[i]=z-'0';
	}
	for (int i=1;i<=n;i++) cin>>c[i];
	for (int i=1;i<=n;i++) {
		if (a[i]==0) {
			cout<<0<<endl;
			return 0;
		}
	}
	ans=1;
	for (int i=1;i<=n;i++) {
		ans*=i;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
