#include<bits/stdc++.h>
using namespace std;
long long n,m,h,g,d,s,e,w,a[100000],x,y,bj=1;
bool cmp(long long p,long long q)
{
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	g=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==g)
		{
			e=i;
			break;
		}
	}
	x=1;
	while(e--)
	{
		if(bj==1)
		{
			y++;
		}
		if(bj==2)
		{
			y--;
		}
		if(y==n+1)
		{
			x++;
			y=n;
			bj=2; 
		}
		if(y==0)
		{
			x++;
			y=1;
			bj=1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
/*
*/
