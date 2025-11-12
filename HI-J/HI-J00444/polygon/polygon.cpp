#include<bits/stdc++.h> 
using namespace std;
int a[1000];
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int n = 0;
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n == 1)
	{
		cout<<0;
	}
	if(n == 2)
	{
		cout<<0; 
	}
	if(n == 3&&a[0]+a[1]>a[2]&&a[2]+a[1]>a[0]&&a[2]+a[0]>a[1])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
