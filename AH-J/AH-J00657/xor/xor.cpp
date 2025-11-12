#include<bits/stdc++.h>
using namespace std;
int n,k,ans,l=1,r=1,s[500005],a[500005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int rp=1;rp<=n;rp++) {
		cin>>a[rp];
		s[rp]=s[rp-1]^a[rp];
	}
	for(int rp=1;rp<=n;rp++) {
		while(abs(s[r+1]-s[l-1])<=k&&r+1<=n&&abs(s[r]-s[l-1])<=abs(s[r+1]-s[l-1])) r++;
		while(abs(s[r]-s[l])>=k&&l+1<=r&&abs(s[r]-s[l])<=abs(s[r]-s[l-1])) l++;
		if(l<=r&&r<=n&&abs(s[r]-s[l-1])==k) {
			ans++;
  			cout<<l<<' '<<r<<'\n';
		}
		r++,l=r;
	}
	cout<<ans;
	return 0;
}
