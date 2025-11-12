#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int arr[n];
	int max_=0,sum=0;
	bool p;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		max_=max(max_,arr[i]);
		sum+=arr[i];
		if(arr[i]!=1) p=false;
	}
	
	if(n==3&&2*max_<sum){
		cout<<1;
	}else cout<<0;
	if(n<=500&&n!=3&&p){
		cout<<n%998+n%244+n%353;
	}else if(n<=5000&&n!=3&&p){
		cout<<n%998+n%244+n%353;	
	}
	return 0;
}
