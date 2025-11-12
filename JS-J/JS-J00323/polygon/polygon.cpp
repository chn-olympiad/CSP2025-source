#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0,a[5006]={},max1=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max1=max(max1,a[i]);
	}
	if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))&&n==3){
		cout<<1;
	}else if(max1==1){
		long long k=1;
		for(int i=0;i<n;i++){
			k*=2;
			k%=998244353;
		}
		long long m=1;
		m=n*(n-1)/2;
		m%=998244353;
		ans=k+998244353-1-n-m;
		ans%=998244353;
		cout<<ans;
	}
	return 0;
}
