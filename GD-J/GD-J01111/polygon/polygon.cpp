#include <iostream>
#include <algorithm>
#include<cstdio>

using namespace std;

int main()
{
	int n,maxn=-1;
	int a[5005];
	cin>>n;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn = max(maxn,a[i]);
	}
	if(n<3)
	{
		cout<<0;
	}
	else if(a[1]+a[2]+a[3]>20)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	
	return 0;
 } 
