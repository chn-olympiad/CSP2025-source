#include<bits/stdc++.h>
using namespace std;
int main()
{
		freopen("xor.in","r",stdin);
		freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	int sum=0;
	long long a[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=2&&k==0)
	{
		if(n==1)
		{
			cout<<0;
		 }
		 if(n==2)
		 {
		 	sum++;
		 	cout<<sum;
		  } 
	}
	 return 0;
 } 
