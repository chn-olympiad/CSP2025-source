#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[500005],n,m,ans;
string s,t;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	b[1]=a[1];
	for (int i=2;i<=n;i++)
	{
		b[i]=(b[i-1]|a[i])-(b[i-1]&a[i]);
	}
	for (int l=1;l<=n;l++)
	{
		for (int i=1;i<=n;i++)
		{
			if (c[l+i-1]==1)
			break;
			if (i==1)
			{
				if (a[l]==m)
				{
					{
				ans++;
				l=i+1;
				break;
			}
				}
			}
			else
			{
				if ((b[l-1+i]|b[l])-(b[l-1+i]&b[l])==m)
			{
				for (int j=l;j<=l+i-1;j++)
				{
					c[j]=1;
				}
				ans++;
				break;
			}
			}
		}
	}
	cout<<ans;
	return 0;
 } 
