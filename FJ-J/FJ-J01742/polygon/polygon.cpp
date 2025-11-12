#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long f(long long a){
	if(a==1)return a%mod;
	return f(a-1)*a%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n,a[5050];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		cout<<1;
		return 0;
	}
	long long ans=0;
	for(int i=3;i<=n;i++){
		long long s=f(n)/f(n-i)%mod;
		s%=mod;
		ans+=s;
		ans%=mod;
	}
	cout<<ans;
	return 0;
} 

