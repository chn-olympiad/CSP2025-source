#include<bits/stdc++.h>
using namespace std;
int ans;
int a[1005],n,f;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!(a[i]-1)) f=1;
	}
	if(!f){
		for(int i=n;i>=3;i--) ans=(ans+(n-i+1)*(i-2*(i-1)/2))%998244353;
		cout<<ans;
		return 0;	
	}
	if(n==3){
		if((a[1]+a[2]+a[3])>2*max(a[1],max(a[2],a[3]))) cout<<1;
		else cout<<0;
		return 0;
	}
	return 0;
}