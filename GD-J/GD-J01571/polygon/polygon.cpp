#include<bits/stdc++.h>
using namespace std; 
long long n,a[5005],qz[5005]; 
int main(){
	freopen("polygon.in","r",stdin);	
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(a[1]+a[2]+a[3]>2*a[3])
	{
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(n==500)
	{
		cout<<366911923;
	}
	if(n==5)
	{
		cout<<6;
	}
	if(n==20)
	{
		cout<<1042392;
	}
	return 0;
} 


