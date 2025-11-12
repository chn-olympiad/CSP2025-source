#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n;
long long a[5005],jc[5005];
void work(){
	long long sum=0,mx=0;
	for(long long i=1;i<=n;i++){
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	if(sum>mx*2)cout<<1;
	else cout<<0;
}
bool check1(){
	for(long long i=1;i<=n;i++){
		if(a[i]!=1)return 0;
	}
	return 1;
}
long long zh(long long x,long long y){
	return (jc[x]%mod)/(jc[y]%mod)/(jc[x-y]%mod)%mod;
}
void work1(){
	long long ans=0;
	for(long long i=3;i<=n;i++){
		for(long long j=1;i<=n;j++){
			if((n-j)<(i-1))break;
			else {
				ans+=zh(n-j,i-1)%mod;
				ans%=mod;
			}
		}
	}
	cout<<ans%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	jc[0]=1;
	jc[1]=1;
	for(long long i=2;i<=5000;i++){
		jc[i]%=mod;
		jc[i]=jc[i-1]*i;
		jc[i]%=mod;
	}
	//for(long long i=1;i<=100;i++)cout<<jc[i]<<" ";
	//cout<<C(6,3);
	cin>>n;
	for(long long i=1;i<=n;i++)cin>>a[i];
	if(n<=3){
		work();
	}
	else if(check1()){
		work1();
	}
	return 0;
}
