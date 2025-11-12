#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5010],f[5010][5010],an[5010],sum[5010],ans;
int qpow(int x,int d){
	int ans=1;
	while(d){
		if(d&1){
			ans=ans*x%mod;
		}
		x=x*x%mod;
		d>>=1;
	}
	return ans;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[a[i]]++;
	}
	sort(a+1,a+n+1);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=5000;j++){
			f[i][j]=f[i-1][j];
			if(j>=a[i]){
				f[i][j]=(f[i][j]+f[i-1][j-a[i]])%mod;
			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=1;j<=5000;j++){
			f[i][j]=(f[i][j-1]+f[i][j])%mod;
		}
	}
	for(int i=1;i<=n;i++){
		ans=(ans+qpow(2,i-1)-f[i-1][a[i]]+mod)%mod;
	}
	cout<<ans;
	return 0;
}
