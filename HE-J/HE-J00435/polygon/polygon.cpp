#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],an;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	sort(a+1,a+n+1); 
		for(int i=1;i<=n;i++)
	{
			b[i]=b[i-1]+a[i];
		
	}

	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
	{
		if(b[j]>=2*a[i])
		an+=(2>>(j-2));
		
	}
	}
	cout<<an;
	return 0;
} 
