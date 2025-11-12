#include<iostream>
#include<cstdio>
using namespace std;
int n,ans=0;
int a[1000001];
int main()
{
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0);
			ans++;
	}
	cout<<ans;
	return 0;
}

