#include<bits/stdc++.h>
using namespace std;
int n;
long long c=0;
long long x;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>x;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int s=0;
			for(int k=j;k>=i;k--)
			{
				s=s xor a[k];
			}
			if(s==x)
			{
				i=j;
				c++;
			}
		}
	}
	cout<<c;
	return 0;
}
