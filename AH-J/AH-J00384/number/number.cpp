#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,sum;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n;j++)
	{
		if(a[j]<a[j+1])
		{
			a[j]=a[j+1];
		}
		else{
			a[j+1]=a[j];
		}
		sum=a[j];
		std::cout<<sum;
	}
	return 0;
}
