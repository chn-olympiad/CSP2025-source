#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	int now=0,ans=0;
	for(int i=1; i<=n; i++) {

		now^=a[i];
//		cout<<now<<endl;
		if(now==k) {
			ans++;
			now=0;

		}
	}
	cout<<ans<<endl;
}