#include<bits/stdc++.h>
using namespace std;
#define QWQ return 0
int main()
{
	
	int n,k,k_0=0,k_1=0;
	cin>>n>>k;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			k_0++;
		}
		if(a[i]==1)
		{
			k_1++;
		}
	}
	if(k==0)
	{
		cout<<k_0;
	}
	if(k==1)
	{
		cout<<k_1;
	}
	QWQ;
}
