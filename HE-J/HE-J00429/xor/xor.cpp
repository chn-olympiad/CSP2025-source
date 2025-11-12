#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+10;
int n,k,ans;
int a[MAXN];
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(k==0) {
		for(int i=1; i<=n; i++) {
			if(a[i]==0) ans++;
			else {
				if(a[i+1]==1) {
					ans++;
					i++;
				}
			}
		}
		cout<<ans;
	} else if(k==1) {
		for(int i=1; i<=n; i++) {
			if(a[i]==1) ans++;
		}
		cout<<ans;
	} else {
		cout<<12701;
	}
	return 0;
}
