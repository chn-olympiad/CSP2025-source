#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(false),cin.tie(nullptr),cin.tie(nullptr);
using namespace std;

const int N=5e5+10;
int n,a[N],maxn=-INT_MAX,s=0;

signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios;
	cin>>n;
	for(int i=1; i<=n; i++)	cin>>a[i];
	if(n<3) {
		cout<<0;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		maxn=max(maxn,a[i]);
		s+=a[i];
	}
	if(n==3) {
		if(s>maxn*2) {
			cout<<1;
			return 0;
		} else {
			cout<<0;
			return 0;
		}
	}
	cout<<998244352;
	return 0;
}
