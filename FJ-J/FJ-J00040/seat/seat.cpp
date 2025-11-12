#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num=1;
	cin >> n >> m;
	cin >> a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin >> a[i];
		if(a[i]>a[1])
		{
			num++;
		}
	}	
	int h,l;
	if(num%n!=0)
	{
		l = num/n+1;
		if(l%2 == 1)
		{
			h = num%n;
		}
		else 
		{
			h = n+1-(num%n);
		}
	}
	else
	{
		l = num/n;
		if(l%2 == 1)
		{
			h=n;
		}
		else 
		{
			h=1;
		}
	}
	cout << l << " "<< h;
	return 0;
}
