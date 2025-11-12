#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,s=0;
	cin >>n;
	int a[n];
	for(int i=0;i<=n;i++)
	{
		cin >>a[i];
		if(a[i]+a[i+1]>a[i+2]&&a[i]-a[i+1]<a[i+2])
		{
			s=s+1;
		}
	}
	cout <<s;
	return 0;
}
