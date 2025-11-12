#include<iostream>
#include<cstdio>
using namespace std;
int n,a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<a[1]+a[n]*n/2;
	return 0;
}


