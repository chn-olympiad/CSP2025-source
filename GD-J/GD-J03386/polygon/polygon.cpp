#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n;
int a[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=3){
		// T 1-3
		// 12 pts
		if(a[1]+a[2]<a[3]||a[1]+a[3]<a[2]||a[2]+a[3]<a[1])cout<<0;
		else cout<<1;
	}
	else{
		// T 15-17 & 18-20
		// 24pts
		long long sum=1;
		for(int i=1;i<=n;i++){
			sum=sum*i;
			sum=sum%mod;
		}
		cout<<sum/6;
	}
	
	
	
	
	
	
	
	//
	return 0;
}
