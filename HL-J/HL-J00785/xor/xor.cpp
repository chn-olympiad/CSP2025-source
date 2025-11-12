#include <iostream>
#define int long long
using namespace std;

int a[500010],q[500010];

signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		q[i]=(q[i-1]^a[i]);
	}
	int ans=0;
	for (int l=1;l<=n;l++) {
		for (int r=l;r<=n;r++) {
			if ((q[l-1]^q[r])==k) {
				l=r;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}