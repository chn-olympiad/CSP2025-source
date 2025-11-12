#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int k=a[1];
	int x=n*m;
	sort(a+1,a+x+1,cmp);
	int d,c,r;
	for(int i=1;i<=x*m;i++)
		if(a[i]==k)
			d=i;
	c=d/m;
	if(d%m==0)
	{
		r=n;
		cout<<c<<" "<<r;
	}
	else
	{
		
			r=d-n*c;
		if(c%2!=0)
			cout<<c+1<<" "<<r;
		else
			cout<<c+1<<" "<<n-r+1;
		
	}
	return 0;
}
