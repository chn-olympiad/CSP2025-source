#include <bits/stdc++.h>
using namespace std;
int s[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >>s[i];
	}
	x=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(s[i]==x)
		{
			int c=(i-1)/n+1,r;
			if(c%2==1)
			{
				r=(i-1)%n+1;
			}
			else r=n-(i-1)%n;
			cout << c << " " << r;
		}
	}
	return 0;
}
