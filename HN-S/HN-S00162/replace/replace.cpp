#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[300010];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		int ans=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i]>>a[i+n]>>a[i+2*n];
		}
		sort(a+1,a+1+n);
		for(int i=n/2+1;i<=n;i++){
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
