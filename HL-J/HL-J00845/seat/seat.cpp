#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,n,m,laoda=0;
	cin>>n>>m;
	int a[n][m],b[n*m];
	for(int i=0;i<n*m;i++)
	{
		cin>>b[i];
	}
	int c=b[0];
	int r=n*m;
	n=0,m=0;
	while(r--)
	{
		n++;
		m++;
		for(int i=0;i<r;i++)
		{
			if(b[i]>laoda)
			{
				laoda=b[i];
			}
		}
		a[n][m]=b[i];
		if(a[n][m]==c)
		{
			cout<<n<<" "<<m;
		}
	}
	
	return 0;
}
