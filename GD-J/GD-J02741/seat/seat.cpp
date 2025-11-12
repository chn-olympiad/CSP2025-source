#include<bits/stdc++.h>
using namespace std;
int a[105],x,y,cnt,n,m;
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
	cnt=a[1];
	int bz=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==cnt)
		{
			bz=i;
			y=i/n;
			if(i%n!=0) y+=1;
			if(y%2==1)
			{
				x=i%n;
				if(x==0) x=n;
			}
			else
			{
				x=n-i%n+1;
				if(x==n+1) x=1;
			}
			break;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
