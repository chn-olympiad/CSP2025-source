#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("numberin","r",stdin)
	freopen("numberout","w",stdout)
	int s;
	cin>>s;
	int a[1000],b;
	for(int i=1;i<=s;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=1000;j++)
	{
		if(a[j]>a[j+1])
		{
			a[j]=b;
			a[j+1]=a[j];
			b=a[j+1];
		}
	}
	for(int c=1,c<=s;c++)
	{
		cout<<a[c];
	}
	return 0;
}
