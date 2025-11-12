#include<bits/stdc++.h>
using namespace std;
int a[12][12];
int s[200];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
	}
	int c=s[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
			if(s[j]<s[j+1])
			{
				swap(s[j],s[j+1]);
			}
		}
	}
	int q=1;
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			for(int j=m;j>=1;j--)
			{
				a[i][j]=s[q];
				if(s[q]==c)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				q++;
			}
		}
		else
		{
			for(int j=1;j<=m;j++)
			{
				a[i][j]=s[q];
				if(s[q]==c)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				q++;
			}
		}
	}
	
	return 0;
}
