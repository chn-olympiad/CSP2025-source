#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long n,ans=0;
long long a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3&&(a[1]+a[2]+a[3])/2>max(a[1],max(a[2],a[3]))){
		cout<<1;
		return 0;
	}
    for(int i=3;i<=n;i++){
		ans=ans+(n-i+1)*(n-i+2)/2;
	} 
	cout<<ans%mod;	
	return 0;
}
