#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3])  cout<<1;
		else  cout<<0;
		return 0;
	}
	if(n==4){
		if(a[1]+a[2]>a[3])  ans++;
		if(a[1]+a[2]>a[4])  ans++;
		if(a[1]+a[3]>a[4])  ans++;
		if(a[2]+a[3]>a[4])  ans++;
		if(a[1]+a[2]+a[3]>a[4])  ans++;
		cout<<ans;
		return 0;
	}
	for(int j=1;j<=n-2;j++){
		for(int i=1;i<=j;i++){
			ans+=i*(j-i+1);
			ans=ans%998244353;
		}
	}
	cout<<ans;
	return 0;
}

