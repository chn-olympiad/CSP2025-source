#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum,cn=0,c=0,r=0;
	int a[10010];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];sum=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==sum)cn=i;
	}//cout<<cn;
	int h=cn/n,k=cn%n;
	if(h%2==1)
	{
		if(k>0)
		{
			c=h+1;
			r=n-k+1;
		}
		else
		{
			c=h;
			r=n;
		}
	}
	else 
	{
		if(k>0)
		{
		    c=h+1;
		    r=k;
		}
		else 
		{
			c=h;
			r=1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
