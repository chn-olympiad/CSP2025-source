#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],b[100005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int x=1,y=1,z=a[1],sum;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
	    b[n*m-i+1]=a[i];
    }
    for(int i=1;i<=n*m;i++)
    {
		if(b[i]==z)
		sum=i;
	}
	int u=0;
	for(int i=1;i<=n*m;i++)
    {
		if(i==sum)
		break;
		if(y==1||y==n)
		{
			if(y==1&&x%2==0)
			{
				u=0;
				x++;
				continue;
			}
			if(y==n&&x%2==1)
			{
				u=1;
				x++;
				continue;
			}
		}
		if(u==0)
		y++;
		if(u==1)
		y--;	
	}
	cout<<x<<" "<<y;
    return 0;
 }
