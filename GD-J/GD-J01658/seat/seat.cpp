#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x=n*m;
	int a[110];
	for (int i=1;i<=x;i++)
		cin>>a[i];
	int sum=a[1];
	sort(a+1,a+x+1);
	int j=1;
	for (int i=x;i>=1;i--)
	{
		if (a[i]==sum)
		{
			sum=j;
			break;
		}
		j++;
	}
	int g=sum%n;
	if (g==0)
		g=n;
	int h=sum/n;
	if (sum%n!=0)
		h++;
	if (h%2==0)
	{
		for (int i=n;i>=1;i--)
		{
			g--;
			if (g==0)
				cout<<h<<" "<<i;
		}
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			g--;
			if (g==0)
				cout<<h<<" "<<i;
		}
	}
	return 0;
}
