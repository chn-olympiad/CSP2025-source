#include<bits/stdc++.h>
using namespace std;
long long const MD=998244353;
long long c(long long n,long long m){
	long long t=1;
	for(long long i=m;i>m-n;i--){
		t*=i;
	}
	for(long long i=2;i<=n;i++){
		t/=i;
	}
	t%=MD; 
	return t;
}
long long a[6000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	for(int i=3;i<=n;i++){
		ans+=c(i,n);
		ans%=MD;
	}
	cout<<ans;
	return 0;
}