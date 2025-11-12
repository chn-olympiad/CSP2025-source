#include <bits/stdc++.h>
using namespace std;

int n,m,c,r;
int a[101],x;

bool s(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n*m;i++)cin >> a[i];
	x=a[0];
	sort(a,a+n*m,s);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==x)
		{
			c=i/n+1;
			r=i%n+1;
			if(c%2==0)r=n-r+1;
			break;
		}
	}
	cout << c << " " << r;
	return 0;
}
