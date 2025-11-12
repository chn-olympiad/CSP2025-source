#include<bits/stdc++.h>
using namespace std;
int a[1005];
int k,w=0,n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	stable_sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--)
	{
		w++;
		if(k==a[i])break;
	}
	int x,y;
	int r=0;
	r=w/n;
	if(w%n!=0)r=r+1;
	if(r%2==1)
	{
		x=w%n;
		if(x==0)x=n;
	}
	else
	{
		int t=w%n;
		if(t==0)t=4;
		x=n-t+1;
	}
	y=w/n;
	if(w%n!=0)y=y+1;
	cout<<y<<" "<<x;
	return 0;
}