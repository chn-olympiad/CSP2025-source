#include <bits/stdc++.h>
using namespace std;
int n,s;
int a[50005];
long long sum[50005],ans,ans1;
int main(){
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]==1) s++;
	}
	if (s==n) {
		ans++;
		for (int i=3;i<n;i++){
			ans1=1;
			for (int j=n;j>=n-i+1;j--){
				ans1=ans1*j%998%244%353;
			}
			for (int j=1;j<=i;j++){
				ans1=ans1/j%998%244%353;
			}
			ans+=ans1;
		}
		cout<<ans;
		return 0;
	}
/*	sort (a+1,a+1+n);
	for (int i=1;i<=n;i++){
		sum[i]=a[i-1]+a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i+3;j<=n;j++){
			if (sum[j]-sum[i]>2*a[j]) ans++;
		}
	}
*/
	return 0;
}
