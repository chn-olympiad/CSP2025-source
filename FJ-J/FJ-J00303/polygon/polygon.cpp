#include <iostream>
#define N 25
#define mod 998244353
using namespace std;

int n,ans;
int a[N];

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=(1<<n); i++) {
		int cnt=0,mx=0,sm=0;
		for(int j=1; j<=20; j++) {
			if(i>>(j-1)&1) {
				mx=max(mx,a[j]);
				sm+=a[j];
				cnt++;
			}
		}
		if(cnt>=3 && sm>2*mx) ans=(ans+1)%mod;
	}
	cout<<ans;
	return 0;
}

