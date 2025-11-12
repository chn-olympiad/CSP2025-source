#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a,b,c;
long long C(int m){
	long long ans=1;
	if(m>n/2){
		m=n-m;
	}
	for(int i=1;i<=m;i++){
		ans=ans*(n-i+1);
		ans=ans/i;
		ans%=mod;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	cin>>a>>b>>c;
	if(n==3){
		if(max(max(a,b),c)*2<a+b+c){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		long long sum=0;
		for(int i=3;i<=n;i++){
			sum+=C(i);
			sum%=mod;
		}
		cout<<sum;
	}
	return 0;
}

