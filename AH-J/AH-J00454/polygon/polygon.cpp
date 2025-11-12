#include<bits/stdc++.h>
using namespace std;
int n,a[5231],ans;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			int sum=0,maxx=-114;
			if(j-i<2) continue;
			for(int k=i; k<=j; k++) sum+=a[k],maxx=max(maxx,a[k]);
			if(sum>maxx) {
					//for(int k=i; k<=j; k++) cout<<a[k]<<" ";
					ans++;
			}
		}
	}
	cout<<ans%998244353;
	return 0;
}
