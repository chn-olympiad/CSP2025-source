#include<bits/stdc++.h>
using namespace std;
int n,t;
long long m,s,c,u;
long long a[500005];
int f[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			s=a[j];
			for(int k=j+1;k<=i;k++)
			{
				s=s^a[k];
				if(f[k]==1)
				{
					t=1;
					break;
				}
			}
			if(s==m&&t==0)
			{
				c++;
				for(int k=j+1;k<=i;k++)
				{
					f[k]=1;
				}
			}
			t=0;
		}
	}
	cout<<c;
}
