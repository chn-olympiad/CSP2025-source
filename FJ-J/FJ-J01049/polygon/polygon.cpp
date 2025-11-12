#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005,mod=998244353;
int n,temp;
int a[MAXN];
int f[MAXN];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		temp=max(temp,a[i]);
	}
	f[0]=1;
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]*i%mod;
	if(temp==1){
		int ans=0;
		for(int i=3;i<=n;i++)
			ans=(ans+f[n]/f[n-i]/f[i]%mod)%mod;
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	if(n==3){
		cout<<((a[1]+a[2])>a[3])<<endl;
		return 0;
	}
	
	return 0;
}
/*
a1+a2
*/
