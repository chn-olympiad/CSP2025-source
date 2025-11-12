#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[7887];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		m=max(m,arr[i]);
	}
	if(n==3){
		if(arr[1]+arr[2]+arr[3]>2*m){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(m==1){
		long long int ans;
		for(int i=3;i<=n;i++){
			ans+= (n-i+2) * (n-i+1) / 2;
			ans=ans%998244353;
		}
		cout<<ans;
	}else{
		long long int ans;
		for(int i=3;i<=n;i++){
			ans+= (n-i+2) * (n-i+1) / 2;
			ans=ans%998244353;
		}
		cout<<ans/2;
	}
	
	return 0;
} 
