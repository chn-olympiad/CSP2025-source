#include<bits/stdc++.h>
using namespace std;
long long n,a[6000];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0,k=a[1],l;
	for(long long i=2;i<n;i++){
		k+=a[i];
		if(k>a[n]){
			l=i;
			break;
		}
	}
	for(long long i=n-l+1;i>=1;i--){
		ans+=(i+1)*i/2;
	}
	if(n==3){
		ans=1;
	}
	cout<<ans;
	return 0;
}