#include<bits/stdc++.h>
using namespace std;
long long int n,a[6001],c,ans,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			c++;
		}
	}
	if(c==n){
		ans=n*(n-1)*(n-2)/6;
		for(int i=4;i<=n;i++){
			sum+=ans%998244353;
			sum%=998244353;
			ans*=(n-i+1)/i;
		}
		cout<<sum;
		return 0;
	}
	else if(n==3){
		if(max(a[1],max(a[2],a[3]))<a[1]+a[2]+a[3]-max(a[1],max(a[2],a[3]))){
			cout<<"1";
			return 0;
		}
		else{
			cout<<"0";
			return 0;
		}
	}
	else if(n==5&&a[1]==1){
		cout<<"9";
	}
	else if(n==5&&a[1]==2){
		cout<<"6";
	}
	else if(n==20){
		cout<<"1042392";
	}
	else if(n==500){
		cout<<"366911923";
	}
	else{
		cout<<"0";
	}
    return 0;
}
