#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a,x=1,y=1,p;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> a;
	for(int i = 2;i<=n*m;i++)
	{
		int z;
		cin >> z;
		if(z>a)
		{
			if(p==0)
			{
				y++;
				if(y>n)
				{
					y=n;
					x++;
					p=1;
				}
			}
			else
			{
				y--;
				if(y<1)
				{
					y=1;
					x++;
					p=0;
				}
			}
		}
	}
	cout << x << " " << y;
	return 0;
}
