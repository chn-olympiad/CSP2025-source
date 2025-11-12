#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i;i>=n;i++)
	{
		cin>>a[i];
	}
	int b;
	for(int j;j>=m*n;j++)
	{
		for(int i=n*m;i>=0;i--)
		{
			if(b<=a[i])
			{
				b=a[i];
			}
		}
		cout<<b;
	}
	return 0;
}
