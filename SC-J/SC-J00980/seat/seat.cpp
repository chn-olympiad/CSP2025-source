#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],b[110][110],sum;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m; i>=1; i--) {
		if(a[i]==sum) {
			sum=n*m-i+1;
			break;
		}
	}
	int ans=ceil(1.0*sum/n);
	sum%=n;
	if(ans%2==0) {
		cout<<ans<<' '<<n-sum+1;
	} else {
		if(sum==0)sum=n;
		cout<<ans<<' '<<sum;
	}
	return 0;
}