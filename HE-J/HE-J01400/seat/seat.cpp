#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int id,num;
}a[500505];
bool cmp(node x,node y)
{
	return x.num>y.num;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int post=0;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			post=i;
		}
	}
	int k=0;
	int x=0,y=1;
	while(k<=n*m)
	{
		if(y%2==1)
		{
			while(x+1<=n)
			{
				x++;
				k++;
				if(k==post)
				{
					cout<<y<<" "<<x;
					return 0;
				}
			}
		}
		else
		{
			while(x-1>=1)
			{
				x--;
				k++;
				if(k==post)
				{
					cout<<y<<" "<<x<<endl;
					return 0;
				}
			}
		}
		if(y+1<=m)
		{
			y++;
			k++;
			if(k==post)
			{
				cout<<y<<" "<<x;
				return 0;
			}
		}
	}
	return 0;
}
