#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],xr,idx,c,r;
bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	cin>>a[i];
	xr=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==xr)	idx=i;
	}
	c=(idx-1)/n+1;
	if(c%2==1)
	{
		r=idx%n;
		if(r==0)	r=n;
	}
	else
	{
		r=n-(idx%n)+1;
		if(r==n+1)	r=1;
	}
	cout<<c<<" "<<r;
	//rp++;
	
	return 0;
} 
