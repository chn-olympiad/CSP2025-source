#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt;
int a[105][105],b[4005];
int x=1,y=1,sum;
bool f;
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	cnt=b[1];
	sort(b+1,b+n*m+1,cmp);
	sum=1;
	f=1;
	while(b[sum]!=cnt)
	{
		if(x==n&&f==1)
		{
			y++;
			f=0;
		}
		else if(x==1&&f==0)
		{
			y++;
			f=1;
		}
		else
		{
			if(f==1)
			{
				x++;
			}
			else
			{
				x--;
			}
		}
		sum++;
	}
	cout<<y<<" "<<x<<"\n";
	return 0;
}
/*
*/
