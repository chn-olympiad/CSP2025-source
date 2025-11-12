#include<bits/stdc++.h>
using namespace std;
int n,a[5003],sum[5003]={1},s,ans,mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=5000;j++)
			ans=(sum[j]+ans)%mod;
		ans=(ans+s)%mod;
		s=s*2%mod;
		for(int j=5001-a[i];j<=5000;j++){
			s=(s+sum[j])%mod;
		}
		for(int j=5000;j>=a[i];j--){
			sum[j]=(sum[j]+sum[j-a[i]])%mod;
		}
	}
	cout<<ans%mod;
	return 0;
}

