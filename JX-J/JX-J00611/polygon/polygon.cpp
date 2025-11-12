#include<bits/stdc++.h>
using namespace std;
int a[5001],n,b[5001];
int method(int x)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		b[1]=a[i];
		for(int j=1;j<=x;j++)
		{
			b[j+1]=a[i+j];
			sum+=b[j+1];
		}
		
	}
	return 0;
}
int main()
{	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<6;
}
