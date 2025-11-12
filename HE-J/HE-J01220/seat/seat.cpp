#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[20][20];
	int b[10001],n,m,z,z1;
	bool z2=false;
	cin>>n>>m;
	z=m*n;
	for(int i=1;i<=z;i++)
	{
		cin>>b[i];
	}
	z1=b[1];
	sort(b+1,b+z+1);
	for(int i=1;i<=m;i++)
	{
		if(z2==false)
		{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=b[z];
			if(a[i][j]==z1)
			{
				cout<<i<<" "<<j;
				return 0;
			}
			z--;
		}
	}
	else 
	{
		for(int x=n;x>0;x--)
		{
			a[i][x]=b[z];
			if(a[i][x]==z1)
			{
				cout<<i<<" "<<x;
				return 0;
			}
			z--;
		}
	}
	if(z2==false) {z2=true;}
	else z2=false;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
