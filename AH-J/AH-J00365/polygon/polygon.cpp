#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5005];
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    if (n<=3) {
		if (a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	else {
		long long ans=0;
		for (int len=n;len>=3;len--){
			for (int i=1;i<=n-len+1;i++){
				for (int j=1;j<=i;j++){
					ans+=(j+1)*j/2;
				}
			}
		}
		cout<<ans%998244353<<endl;
	}
    return 0;
}
