#include <bits/stdc++.h>
using namespace std;
int a[500000],b[1001][1001],c[1001],d[1001],zs=-1,jzs,ys;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		for (int j=1;j<=i;j++)
		{
			b[j][i]=(b[j][i-1]^a[i]);
			if (b[j][i]==k)
			{
				if (d[j]==0)
				{
					d[j]=i;
					ys++;
					c[ys]=j;
				}
			}
		}
	}
	if (ys==0)
	{
		cout<<0;
		return 0;
	}
	sort(c+1,c+ys+1);
	for (int i=1;i<=ys;i++)
	{
		int q=d[c[i]];
		jzs=1;
		for (int j=i+1;j<=ys;j++)
		{
			if (c[j]>q)
			{
				jzs++;
				if (d[c[j+1]]<d[c[j]])
				{
					if (d[c[j+2]]<d[c[j+1]])
					{
							if (d[c[j+3]]<d[c[j+2]])
							{
								q=d[c[j+3]];
							}
							else
							{
								q=d[c[j+2]];
							}
					}
					else
					{
						q=d[c[j+1]];
					}
				}
				else
				{
					q=d[c[j]];
				}
			}
		}
		zs=max(jzs,zs);
	}
	cout<<zs;
	return 0;
}
