#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long a,b,c[100100],d,e,k=-1,l=0;
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>c[i];
		k=max(k,c[i]);
	}
	if(k==1)
	{
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=i;j++)
			{
				if(i-j>=2)
				{
					l++;
				}
			}
		}
	}
	cout<<l%998244353;
	return 0;
}
