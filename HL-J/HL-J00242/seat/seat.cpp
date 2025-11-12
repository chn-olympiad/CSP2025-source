#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int num=0;
	int a[105];
	for (int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	int r=a[1];
	sort(a[1],a[n*m+1]);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i] == r)
		{
			break;
		}
		num++;
	}
	int x=num/n;
	int y=num%n;
	if (num%n==0)
	{
		cout << x << " " << n;
	}
	if (num%n!=0)
	{
		cout << x << " " << y; 
	}
	
	return 0;
}
