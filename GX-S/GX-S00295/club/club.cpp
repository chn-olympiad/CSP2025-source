#include <bits/stdc++.h>
using namespace std;
int a[5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	cout << endl;
	for(int q=1;q<=t;q++)
	{
		int n;
		cin >> n;
		int x=0,y=0,z=0;
		int k=0;
		for(int i=1;i<=n;i++)
		{
			a[1]=0;
			a[2]=0;
			a[3]=0;
			for(int j=1;j<=3;j++)
			{
				cin >> a[j];
			}
			int s=max(max(a[1],a[2]),max(a[1],a[3]));
			if(s==a[1] && x<n/2)
			{	
				x++;
				k+=a[1];
			}
			else if(s==a[1] && x==n/2)
			{
				s=max(a[2],a[3]);
				if(s==a[2])
				{
					y++;
					k+=a[2];
				}
				if(s==a[3])
				{
					z++;
					k+=a[3];
				}
			}
			if(s==a[2] && y<n/2)
			{
				y++;
				k+=a[2];
			}
			else if(s==a[2] && y==n/2)
			{
				s=max(a[1],a[3]);
				if(s==a[1])
				{
					x++;
					k+=a[1];
				}
				if(s==a[3])
				{
					z++;
					k+=a[3];
				}
			}
			if(s==a[3] && z<n/2)
			{
				z++;
				k+=a[3];
			}
			else if(s==a[3] && z==n/2)
			{
				s=max(a[1],a[2]);
				if(s==a[1])
				{
					x++;
					k+=a[1];
				}
				if(s==a[2])
				{
					y++;
					k+=a[2];
				}
			}
		}
		cout << k << endl;
	}
	return 0;
}
