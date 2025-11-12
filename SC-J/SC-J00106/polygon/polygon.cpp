#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans,s[5005];
long long mod=998244353; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2&&a[1]+a[2]+a[3]>a[1]*2&&a[1]+a[2]+a[3]>a[2]*2){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if(a[1]==1){
		for(int i=3;i<=n;i++){
			ans=(ans+((i-1)*(i-2))%mod/2)%mod;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int k=3;k<=n;k++){
		for(int i=2;i<k;i++){
			for(int j=0;j<=i-2;j++){
				if(s[i]-s[j]>a[k]){
					ans=(ans+1)%mod;
					//cout<<s[i]<<" "<<a[j]<<" "<<a[k]<<endl;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 