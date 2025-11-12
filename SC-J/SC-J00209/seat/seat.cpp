#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[105]={0};
	int b[105]={0};
	int n,m,p,q;
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>a[i*m+j];
		}
	}
	int s=a[1];
	sort (a,a+m*n+1);
	for (int i=m*n;i>=1;i--)
	{
		b[m*n-i+1]=a[i];
	}
	for (int i=1;i<=m*n;i++)
	{
		if (b[i]==s)
		{
			p=i;
			break;
		}
	}
	for (int i=1;i<=m;i++)
	{
		if (p<=i*n)
		{
			q=i;
			break;
		}
	}
	if (q%2!=0)
	{
		cout<<q<<" "<<p-(q-1)*n;
	}
	else
	{
		cout<<q<<" "<<n-(p-(q-1)*n)+1;
	}
	return 0;
}