#include<bits/stdc++.h>
#define N 110
using namespace std;
int n,m,qwq,t,fang=3,x=1,y=1;
int a[N];
int dx[10],dy[10];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	dx[1]=-1;
	dy[2]=1;
	dx[3]=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	qwq=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
		if(a[i]==qwq)
			t=i;
	if(n==1)
	{
		cout<<m-t+1<<" 1";
		return 0;
	}
	for(int i=n*m;i>t;i--)
	{
		x+=dx[fang];
		y+=dy[fang];
		if(fang&1)
		{
			if(fang==3&&x==n)
				fang=2;
			if(fang==1&&x==1)
				fang=2;
		}
		else
		{
			if(fang==2&&x==n)
				fang=1;
			if(fang==2&&x==1)
				fang=3;
		}
	}
	cout<<y<<' '<<x;
	return 0;
}
