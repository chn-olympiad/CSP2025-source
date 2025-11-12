#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],r,scsp[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	int k=0;
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				scsp[i][j]=a[n*m-k];
				if(a[n*m-k]==r)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				k++;
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				scsp[i][j]=a[n*m-k];
				if(a[n*m-k]==r)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				k++;
			}
		}		
	}
	return 0;
}
