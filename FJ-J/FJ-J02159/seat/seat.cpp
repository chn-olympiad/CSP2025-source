#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],x,h=1,l=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin >>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if (a[i]==x)
		{
			cout <<h<<" "<<l;
			return 0;
		}
		if (l==1&&h%2==0)
		{
			h++;
		}
		else if (l==n&&h%2==1)
		{
			h++;
		}
		else if (h%2==0)
		{
			l--;
		}
		else
		{
			l++;
		}
	}
	return 0;
}

