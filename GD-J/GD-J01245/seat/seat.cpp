#include<bits/stdc++.h>
using namespace std;
int n,m,a[1145],pos,h,l,r;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	pos=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{ 
		if(a[i]==pos)
		{
			l=ceil((1.0*i/n));
			r=i-(l-1)*n;
			if(l%2==1)
			{
				h=r;
			}
			else
			{
				h=n-r+1;
			}
			break;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
