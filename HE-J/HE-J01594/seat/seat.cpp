#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,z,c,w,s;
int a[1005];
int b;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n*m;i++)
	{
		for(j=1;j<=n*m;j++)
		{
			if(a[i]<a[j])
			{
				b=a[i];
			}
			else if(a[i]=a[j])
				{
					b=a[j];
				}
		}
	}
	for(i=1;i<=n*m;i++)
	{
		a[i]=c;
		c=i;
	}
	cout<<c; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
