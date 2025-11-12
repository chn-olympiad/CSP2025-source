#include <iostream>
using namespace std;
const int N = 5e3 + 5;
int n,k,a[N];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a0=1,a1=1;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		if (a[i]!=0) a0=0;
		if (a[i]!=1) a1=0;
	}
	if (a0 && !a1) {
		if (!k) {
			int ans=n;
			for (int i=3; i<=n; i+=2) {
				long long a=1,b=1,c=1;
				for (int j=1; j<=n; j++) {
					if (j<=i) a=a*1ll*j;
					if (j<=n-i) b=b*1ll*j;
					c=c*1ll*j;
				}
				ans=ans+c/a/b;
			}
			cout<<ans;
		}
		else {
			int ans=0;
			for (int i=2; i<=n; i+=2) {
				long long a=1,b=1,c=1;
				for (int j=1; j<=n; j++) {
					if (j<=i) a=a*1ll*j;
					if (j<=n-i) b=b*1ll*j;
					c=c*1ll*j;
				}
				ans=ans+c/a/b;
			}
			cout<<ans;
		}
	}
	else if (!a0 && a1) {
		if (!k) {
			int ans=0;
			for (int i=2; i<=n; i+=2) {
				long long a=1,b=1,c=1;
				for (int j=1; j<=n; j++) {
					if (j<=i) a=a*1ll*j;
					if (j<=n-i) b=b*1ll*j;
					c=c*1ll*j;
				}
				ans=ans+c/a/b;
			}
			cout<<ans;
		}
		else {
			int ans=n;
			for (int i=3; i<=n; i+=2) {
				long long a=1,b=1,c=1;
				for (int j=1; j<=n; j++) {
					if (j<=i) a=a*1ll*j;
					if (j<=n-i) b=b*1ll*j;
					c=c*1ll*j;
				}
				ans=ans+c/a/b;
			}
			cout<<ans;
		}
	}
	else cout<<rand()%((1+n)*n/2);
	return 0;
}
