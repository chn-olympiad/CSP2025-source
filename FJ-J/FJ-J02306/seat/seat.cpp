#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,aa=0,s=0,x=0;
	cin>>n>>m;
	int a[n*m+1];
	for (int i=0;i<n*m;i++)
	{
		int q;
		cin>>q;
		if (i==0)
		{
			aa = q;
		}
		a[i] = q;
		x++;
	}
	for (int i=0;i<=x;i++)
	{
		for (int j=0;j<=i;j++)
		{
			if (a[j]<=a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
	for (int i=0;i<x;i++)
	{
		if (a[i]==aa)
		{
			s=i+1;
		}
	}
	if (s%2==0)
	{
		cout<<s/2<<" "<<m-s%m;
	}
	else{
		cout<<s/2<<" "<<n*m-(s/2)*n+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}