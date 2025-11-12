#include<bits/stdc++.h>
using namespace std;
int m,n,s,t,t1,a[150],x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++)
	{
		cin>>a[i];
		if(i==1)t=a[i];
		for(int j=i-1;j>=1;j--)
		{
			if(a[j+1]>a[j])swap(a[j+1],a[j]);
			else break;
		}
	}
	for(int i=1;i<=s;i++)
	{
		if(a[i]==t)
		{
			t1=i;
			break;
		}
	}
	x=t1/n;
	y=t1%n;
	if(t1%n!=0)x++;
	if(y==0)y=n;
	if(x%2==0)
	{
		y=m-y+1;
	}
	cout<<x<<" "<<y;
	return 0;
}
