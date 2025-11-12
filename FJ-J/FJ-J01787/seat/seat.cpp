#include <bits/stdc++.h>
using namespace std;
int a[105],c; 
bool cmp(int x,int y)
{
	if(x<y)return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;++i)
	{
		cin >> a[i];
		if(i==1)
			c=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i)
	{
		if(a[i]==c)
		{
			if(i<=n)
			{
				cout << 1 << " " << i;
				return 0;
			}
			if(i%4==0)
			{
				cout << i/4 << " ";
			}
			else
			{
				cout << i/4+1 << " ";
			}
			if(i%(n*2)>n)
			{
				cout << i%(n*2)/n+1;
			}
			else if(i%(n*2)<=n) 
			{
				cout << i%(n*2)/n;
			}
		}
	}
	return 0;
}
