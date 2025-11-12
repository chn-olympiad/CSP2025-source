#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],sum[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=0;k<j;k++){
				if(a[i]<sum[i-1]-(sum[j]-sum[k])){
					ans++;
					ans%=998244353;
				}
			}
		}
	}
	for(int i=3;i<=n;i++){
		if(sum[i-1]>a[i]){
			ans++;
			ans%=998244353;
		}
	}
	cout<<ans%998244353;
	return 0;
}
