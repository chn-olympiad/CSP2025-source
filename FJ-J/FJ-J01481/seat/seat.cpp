#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],s[15][15],x,k=1;
bool cmp(int q,int p)
{
	return q>p;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2)
		{
			for(int j=1;j<=n;j++)
			{
				s[j][i]=a[k];
				if(a[k]==x)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				k++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				s[j][i]=a[k];
				if(a[k]==x)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				k++;
			}
		}
	}
	return 0;
}

