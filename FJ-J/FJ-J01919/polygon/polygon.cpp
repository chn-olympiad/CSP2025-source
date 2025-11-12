#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

const int MOD=998244353, N=5010;
long long a[N],s[N],n,max=-1;
bool f1=true;

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i] != 1) f1 = false;
	}
		
	sort(a+1,a+n);
	if(n==3) {
		if(a[1] + a[2] > a[3]) {
			cout<<1;
		} else {
			cout<<0;
		}
		return 0;
	} else if(f1) {
		long long ans=0,t=1;
		for(int i=3;i<=n;i++) {
			t = 1;
			for(int j=0;j<i;j++) {
				t *= (n-j);
			}
			ans += t;
			ans %= MOD;
		}
		cout<<ans;
	}
	
	return 0;
}
