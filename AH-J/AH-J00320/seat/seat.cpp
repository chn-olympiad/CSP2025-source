#include<bits/stdc++.h>
using namespace std;
int n,m,z,a[205],t,w,x=1,y=1,s;
int main()
{
  freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);
	cin>>n>>m;
	z=n*m;
	for(int i=1;i<=z;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+z+1,greater<int>());
	for(int i=1;i<=z;i++)
	{
		if(a[i]==t)
		{
			w=i;
			break;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int f=1;
		if(i%2==0)
		{
			f=-1;
		}
		for(int j=1;j<=n;j++)
		{
			s++;
			if(s==w)
			{
				cout<<y<<' '<<x;
				return 0;
			}
			if((f==-1&&x>1)||(f==1&&x<n))
			//if(j<n)
			{
				x+=f;
			}
			else
			{
				y++;
			}
		}
	}
	return 0;
}
