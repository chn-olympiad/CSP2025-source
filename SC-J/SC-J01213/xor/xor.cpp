#include<iostream>
using namespace std;
long long a[5000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,l=0,c=0,j;
	cin>>n>>k;
/*	if(k==0)
	{
		cout<<0;
		return 0;
	}*/
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(long long i=0;i<n;i++)
	{
		l=a[i];
		for(j=i+1;j<n;j++)
		{
			if(l==k)
			{
				i=j;
				break;
			}
			l^=a[j];
		}
		if(j<n-1)
			c++;
	}
	cout<<c+1;
}