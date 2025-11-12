#include<bits/stdc++.h>
using namespace std;
int a[10100];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdin);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[1]+a[2]<=a[3]||a[2]+a[3]<=a[1]||a[1]+a[3]<=a[2])
	{
		cout<<0;
	}
	else
	{
		if(a[1]>=a[2]&&a[1]>=a[3])cout<<a[1];return 0;
		if(a[2]>=a[1]&&a[2]>=a[3])cout<<a[2];return 0;
		if(a[3]>=a[1]&&a[3]>=a[2])cout<<a[3];return 0;
	}
	return 0;
} 