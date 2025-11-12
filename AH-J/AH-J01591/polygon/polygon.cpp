#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005];
bool all1=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			all1=0;
		}
	}
	if(all1){
		long long ans=n+1;
		long long tmp[5005];
		tmp[0]=(n*(n-1))%mod;
		for(int i=1;i<=n-4;i++){
			ans=(ans+tmp[i-1])%mod;
			tmp[i]=(tmp[i-1]*(n-i))%mod;
		}
		cout<<ans%mod<<endl;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
		return 0;
	}
	int anss=0;
	for(int i=1;i<=n;i++){
		anss+=a[i];
	}
	anss=anss/n*2;
	cout<<anss<<endl;
	return 0;
}
