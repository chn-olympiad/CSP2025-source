#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,e,x=1,y=1;
	cin>>n>>m;
	int a[n*m+1];
	for(i=1;i<=n*m;i++) cin>>a[i];
	e=a[1];
	for(i=1;i<=n*m;i++)
	{
		int max=0,s;
		for(j=1;j<=n*m;j++)
		{
			if(a[j]>max)
			{
				max=a[j];
				s=j;
			}
		}
		if(max==e)
		{
			cout<<x<<" "<<y;
			return 0;
		}
		if(x%2==1)
		{
			y++;
			if(y>m)
			{
				x++;
				y=m;
			}
		}
		else if(x%2==0)
		{
			y--;
			if(y<1)
			{
				x++;
				y=1;
			}
		}
		a[s]=0;
	}
	return 0;
}
