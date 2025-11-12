#include<bits/stdc++.h>
using namespace std;
int n,m,t,p,x=1,y=1;
int a[110];
bool f;
bool bym(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	t=n*m;
	for(int i=0;i<t;i++)
	{
		cin>>a[i];
	}
	p=a[0];
	sort(a,a+t,bym);
	for(int i=0;i<t;i++)
	{
		if(a[i]==p)
		{
			cout<<x<<" "<<y;
			return 0;
		}
		if(f==0)
		{
			if(y<m)
			{
				y++;
			}
			else if(y==m)
			{
				x++;
				f=1;
			}
		}
		else
		{
			if(y>1)
			{
				y--;
			}
			else if(y==1)
			{
				x++;
				f=0;
			}
		}
	}
	return 0;
}
