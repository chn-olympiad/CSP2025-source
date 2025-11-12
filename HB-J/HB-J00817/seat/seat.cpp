#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int li[n*m]={0};
	for (int i=0;i<n*m;i++)
	{
		cin>>li[i];
	}
	int fi=li[0],fidex;
	sort(li,li+m*n);
	for (int i=0;i<n*m/2;i++)
	{
		swap(li[i],li[m*n-i-1]);
	}
	
//	for (int i=0;i<n*m;i++)
//	{
//		cout<<li[i];
//	}

	for (int i=0;i<n*m;i++)
	{
		if (li[i]==fi)
		{
			fidex=i+1;
		}
	}

	int r,c;
	c=(fidex-1)/n+1;

	if (c%2==1)
	{
		r=fidex%n;
		if (r==0)
		{
			r=n;
		}
		cout<<c<<" "<<r;
	}
	else if (c%2==0)
	{
		r=n-fidex%n+1;
		if (r==0)
		{
			r=n;
		}
		cout<<c<<" "<<r;
	}
	

	
	return 0;
}
