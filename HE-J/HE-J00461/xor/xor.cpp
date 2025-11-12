#include<bits/stdc++.h>
using namespace std;
int a[500010],cntt[500010],k,n,ans;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]==k) {
			ans++;
			cntt[i]==1;
		}
		for(int j=1;j<=i;j++) {
			int cntt=a[j];
			for(int x=j+1;x<=i;x++) {
				if(cntt[a]==1) {
					continue;
				}
				cntt=cntt^a[x];
				if(x==i&&cntt==k) {
					ans++;
					for(int y=j+1;y<=i;y++) cntt[a]==1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
