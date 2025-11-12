#include<bits/stdc++.h>
using namespace std;
int a[1110000];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,k;
	cin>>n;
	int sum=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n<=3) {
		if(n<=2)cout<<0<<endl;
		else if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) {
			cout<<1<<endl;
		} else cout<<0<<endl;
	}
	else {
		long long ans=1;
	    for(int i=4;i<=n;i++){
	    		for(int k=n;k>=i;k--){
	    			ans=ans*k;
	    			ans=ans%998244353; 
				}
		}
		cout<<ans<<endl;
	}
	return 0;
}
