#include<iostream>
#include<algorthm>
#include<cstdio>
using namespace std;
int a[105];
int s[15][15];
int main()
{
	int n,m;
	int sum;
	cin >> n >> m;
	for(int i=0;i<n*m,i++)
	{
		cin >> a[i];
	}
	sum=a[0];
	sort(a+0,a+0+n*m);
	for(int i=0;i<n*m;i++)
	{
		for(int j=0;j<n*m;j++)
		{
			if(a[i]<a[i+1])
			{
				a[i+1]=a[i];
				a[i]=a[i+1];
			}
		}
	}
	s[15][15]=s[n][m];
	for(int i=0;i<n*m;i++)
	{
		s=a;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=sum)
			{
				cout << s[i][j] << endl;
			}
		}
	}
}



















