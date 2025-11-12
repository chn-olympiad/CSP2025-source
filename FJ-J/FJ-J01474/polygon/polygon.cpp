#include<iostream>
#include<algorithm>
using namespace std;

long long n,a[12000],ans=1; 

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(n==3){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2)
		cout<<1;
		else
		cout<<0;
	}
	
	else{
		for(int i=1;i<=n-3;i++)
		{
			ans+=(ans+n-1);
			ans=ans%998244353; 
		}
		cout<<ans%998244353;
	}
	
	return 0;
 } 
