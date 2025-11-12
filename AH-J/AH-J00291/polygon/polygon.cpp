#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],sum[5005],cnt;
long long mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	if(n==3){
		if(a[n]*2<sum[n]){
			cout<<1%mod;
		}
		else cout<<0;
		return 0;
	}
	for(long long s=3;s<=n;s++){
		for(long long i=1;i<=n;i++){
			if(sum[i+s-1]-sum[i-1]>a[i]*2){
				cnt++;
			}
		}
	}
	cout<<cnt%mod;
	return 0;
}
