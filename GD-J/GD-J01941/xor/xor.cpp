#include <bits/stdc++.h>
using namespace std;
int n,k,e,ans,a[1000000];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false); 
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		a[i]=a[i]^a[i-1];
	}
	for(int i=1;i<=n;i++) {
		for(int o=e;o<i;o++) {
			if((a[i]^a[o])==k) {
				e=i,ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
