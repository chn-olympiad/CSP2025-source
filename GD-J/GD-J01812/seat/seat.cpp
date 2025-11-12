#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int cur=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int x=0;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==cur)
		{
			x=i;
			break;
		}
	}
	int c=0,r=0;
	c= x%n==0 ? x/n : x/n+1;
	if(c%2==1)
	{
		r= (x%n==0) ? n : x%n; 
	}
	else
	{
		r= (x%n==0) ? 1 : n-x%n+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
