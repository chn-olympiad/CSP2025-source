#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,a2,a5=1,a7,a9,a8;
	double a3;
	cin>>n>>m;
	a1=m*n;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	a2=a[1];
	sort(a+1,a+a1+1);
	for(int i=m*n;i>=1;i--)
	{
		if(a[i]==a2)
		{
			a3=a5;
			break;
		}
		a5++;
	}
	a7=ceil(a3/m);
	a8=a3;
	if(a7%2==0)
	{
		a9=m-a8%m+1;
	}
	else
	{
		if(a8%m==0)
		{
			a9=m;
		}
		else
		{
			a9=a8%m;
		}
	}
	cout<<a7<<" "<<a9;
	return 0;
}
