#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[5005];
int A(int n,int k){
	int sum=1;
	for(int i=n;i>=n-k+1;i--){
		sum=(sum*i)%mod;
	}
	return sum%mod;
}
int C(int n,int m){
	int s1=A(n,m),s2=A(m,m);
	return s1/s2;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,fl=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)fl=0;
	}
	if(n==3){
		int sum=a[1]+a[2]+a[3];
		int mx=max({a[1],a[2],a[3]});
		if(sum>mx*2)cout<<1<<'\n';
		else cout<<0<<'\n';
		exit(0);
	}else if(fl){
		int sum=1;
		for(int i=n-1;i>=3;i--){
			sum=(sum+C(n,i))%mod;
		}
		cout<<sum<<'\n';
	}else{
		sort(a+1,a+1+n);
		cout<<2*n-1<<'\n';
	}
	return 0;
} 
