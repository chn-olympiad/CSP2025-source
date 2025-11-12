#include<bits/stdc++.h>

using namespace std;
int a[110][110];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;//m line n hang
	cin>>n>>m;
	int k=1;
	
/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<a[j][i]<<' ';
		}
		cout<<'\n';
	}
*/
	int sum=1;
	int w=0;
	cin>>w;
	for(int i=0;i<n*m-1;i++)
	{
		int t;
		cin>>t;
		if(t>w)
		{
			sum++;
		}
	}	
	for(int i=1;i<=m;i++)
	{
		if(i&1) //ji shu
		{
			for(int j=1;j<=n;j++)
			{
				if(k++==sum)
				{
					cout<<i<<' '<<j<<'\n';
					return 0;
				}
			
			}
		}
		else
		{
			for(int j=n;j>0;j--)
			{
				if(k++==sum)
				{
					cout<<i<<' '<<j<<'\n';
					return 0;
				}
			}
		}
	}
	return 0;
}

