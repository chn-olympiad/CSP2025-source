#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,max=0,z,r;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>x;
			if(x>max)
			{
				z=1;
				r=1;
				continue;
			}
			else
			{
				z++;
				if(z>n)
				{
					r++;
				}
			}
		}
	}
	cout<<z<<" "<<r;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
