#include <bits/stdc++.h>
using namespace std;

int n;

long long jc(long long z){
	if(z==1||z==0)
		return 1;
	else
		return jc(z-1)*z%998244353;
}

long long ans=0;

int main(){
	cin>>n;
	int a[n+2];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n>3){
		for(int i=2;i<=n;i++){
			ans+=(jc(n-2)/jc(n-i));
			ans%=998244353;
		}	
		cout<<ans<<endl;		
	}
	else{
		int lonst=max(max(a[0],a[1]),a[2]);
		if(a[0]+a[1]+a[2]>lonst*2) cout<<"1"<<endl;
		else cout<<"0"<<endl;		
	}
	return 0;
}