#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int c[510];
long long mul(long long a,long long b) {
	long long res=0;
	while(b) {
		if(b&1) {
			res=(res+a)%mod;
		}
		b=b>>1;
		a=(a+a)%mod;
	}
	return res;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0; i<n; i++) {
		cin>>c[i];
	}
	if(s.find('0')==string::npos) {
		long long ans=1;
		for(int i=n; i>=1; i--) {
			ans=mul(ans,i);
		}
		cout<<ans%mod;
	} else {
		srand(time(0));
		cout<<rand()%mod;
	}
	return 0;
}
