#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],t,x,y;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(t==a[i]) 
		{
			x=i;
			break;
		}
	}
	y=x%n;
	x/=n;
	if(y!=0) x++;
	if(x%2==0) y=n-y+1;
	if(y==0) y=n;
	cout<<x<<" "<<y<<endl;
	return 0;
}

