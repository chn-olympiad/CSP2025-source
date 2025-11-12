#include<bits/stdc++.h>
using namespace std;
int n,m,s,x=1,y=1,r;
struct student{
	int id,cj;
}a[105];
bool cmp(student a,student b)
{
	return a.cj>b.cj;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	r=n*m;
	for(int i=1;i<=r;i++)
	{
		cin>>a[i].cj;
		a[i].id=++s;
	}
	sort(a+1,a+1+r,cmp);
	for(int i=2;i<=r;i++)
	{
		if(x==n)
		{
			if(y%2==1)
			{
				y++;
				x=n+1;
			}
		}
		else if(x==1)
		{
			if(y%2==0)
			{
				y++;
				x=0;
			}
		}
		if(y%2==1)
		{
			++x;
		}
		else
		{
			--x;
		}
		if(a[i].id==1)
		{
			cout<<y<<" "<<x;
			return 0;
		}
	}
	return 0;
}

