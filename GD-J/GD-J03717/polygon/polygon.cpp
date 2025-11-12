#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans,mod=998244,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
    if(n==3){
    	if(a[1]+a[2]+a[3]>a[3]*2)ans=1;
	}
	else if(a[n]<=1){
		for(int i=3;i<=n;i++){
			long long s1=1,s2=1;
			for(int j=n;j>n-i;j--){
				s1*=j;
				s2*=(n-j+1);
			}
			ans+=(s1/s2)%mod;
		}
	}
	else ans=1;
	cout<<ans;
	return 0;
}
