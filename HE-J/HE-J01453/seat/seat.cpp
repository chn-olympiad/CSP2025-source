#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	num=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==num)
		{
			num=n*m-i;
			break;
		}
	}
	int x=0,y=0;
	if(num%n==0)
	{
		x=num/n;
		if(x%2==0) y=1;
		else y=n;
	}
	else 
	{
		x=num/n+1;
		if(x%2==0) y=n-(num%n)+1;
		else y=num%n;
	}
	cout<<x<<" "<<y;
	return 0;
}
