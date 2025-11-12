#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node
{
	int a,id;
}e[10005];
bool cmp(node q,node p)
{
	return q.a>p.a;
}
int x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>e[i].a;
		e[i].id=i;
	}
	int len=n*m;
	sort(e+1,e+1+len,cmp);
	x=y=1;
	for(int i=1;i<=len;i++)
	{
		if(e[i].id==1)
		{
			cout<<y<<" "<<x;
			return 0;
		 } 
		if(y%2==1)
		{
			x++;
			if(x>n)
			{
				x=n;
				y++;
			}
		}
		else
		{
			x--;
			if(x<1)
			{
				y++;
				x=1;
			}
		}
	}
	return 0;
}
