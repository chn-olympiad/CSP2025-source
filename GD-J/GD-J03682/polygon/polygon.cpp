#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],sum[10005],ma,ans,mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
    sort(a+1,a+1+n);
    sum[0]=1;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=a[i];j++){
    		ans+=sum[j];
    		ans%=mod;
    		//cout<<j<<" "<<sum[j]<<endl;
		}
		for(int j=ma;j>=a[i];j--){
			sum[j]+=sum[j-a[i]];
			sum[j]%=mod;
		}
	}
	long long two=1;
	for(int i=1;i<=n;i++){
		two*=2;
		two%=mod;
	}
	long long u=(two+mod-1)%mod;
	cout<<(u-n+2*mod-ans)%mod;
	return 0;
}
