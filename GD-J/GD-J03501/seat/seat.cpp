#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int p=a[1],t;
	sort(a+1,a+1+n*m);
	int x=1,y=1,v=1;
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==p)
		{
			cout<<x<<' '<<y;
			break;
		}
		if(v==1)
		{
			y++;
			if(y==n+1)
			{
				y--;
				x++;
				v=2; 
			}
		}
		else if(v==2)
		{
			y--;
			if(y==0)
			{
				y++;
				x++;
				v=1;
			}
		}
	}
		
	return 0;
 } 
