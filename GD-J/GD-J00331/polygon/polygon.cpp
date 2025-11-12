#include<bits/stdc++.h>
using namespace std;
int n,a[5005],lo[25];
const int mod=998244353;
int f(int x,int k){
	long long sum1=1,sum2=1;
	while(k>0){
		sum2*=x;
		sum2%=mod;
		if(k&1)sum1*=sum2,sum1%=mod;
		k/=2; 
	}
	return sum1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		int ans=0;
		lo[0]=1;
		for(int i=1;i<=n;i++)lo[i]=lo[i-1]*2;
		for(int i=0;i<lo[n];i++){
			int ma=0,sum=0;
			for(int j=1;j<=n;j++)
				if((i>>(j-1))&1){
					ma=max(ma,a[j]);
					sum+=a[j];
				}
			if(sum>ma*2)ans++;
		}
		cout<<ans; 
	}
	else {
		long long ans=0;
		for(int i=3;i<=n;i++){
			long long sum1=1,sum2=1;
			for(int j=1;j<=i;j++){
				sum1*=1ll*(n-j+1);
				sum2*=1ll*j;
				sum1%=mod;
				sum2%=mod;
			}
			ans+=(1ll*sum1*f(sum2,mod-2))%mod;
			ans%=mod;
		} 
		cout<<ans; 
	}
	return 0;
} 
