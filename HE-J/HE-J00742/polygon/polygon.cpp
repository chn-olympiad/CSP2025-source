#include<bits/stdc++.h>
#define int long long
using namespace std;
int C(int a,int b){
	int sum=1,a1=a,a2=a,ans=1;
	while(a1--){
		sum*=b;
		b--;
	}
	while(a2--){
		ans*=a2;
	}
	ans*=a;
	sum/=ans;
	return sum;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,mx=-10,ans=0;
	cin>>n;
	int a[n+10],he=0;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
		mx=max(mx,a[i]);	
		he+=a[i];
	}
	if(n<3){
	    cout<<0;
		return 0;	
	}
	if(n==3){
	   	if(he>2*mx){
	   		cout<<1;
	   		return 0;
		}
		else{
		    cout<<0;
		    return 0;	
		}
	}
	if(mx==1){
		for(int i=3;i<=n;i++){
			ans+=C(i,n);
			ans%=998244353; 
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
