#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,mx=INT_MIN,mn=INT_MAX;
	cin>>n>>k;
	int a[n+19];
	for(int i=1;i<=n;i++){
	    cin>>a[i];
		mx=max(a[i],mx);
		mn=min(a[i],mn);
	}
	if(mn==mx){
		if(k==0) cout<<n/2; 
		else if(mx==k) cout<<n;
		else cout<<0;
	}  
	else cout<<n;
	return 0;
}
