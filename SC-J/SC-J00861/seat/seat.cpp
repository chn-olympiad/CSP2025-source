#include<bits/stdc++.h>
using namespace std;
int n,m,a[505];
bool cmp(int a,int b)
{
	return a>b;
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
	int jy=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1;
	for(x;x<=n*m;x++)
	{
		if(a[x]==jy)
		break;
	}
	for(int i=0;i<=m-1;i++)
	{
		if((i+1)%2==1)
		{
			if(x==i*n+1)
			cout<<i+1<<" "<<1;
			if(x==(i+1)*n)
			cout<<i+1<<" "<<n;
			if(x>i*n+1&&x<(i+1)*n)
			cout<<i+1<<" "<<x-i*n;
		}
		if((i+1)%2==0)
		{
			if(x==i*n+1)
			cout<<i+1<<" "<<n;
			if(x==(i+1)*n)
			cout<<i+1<<" "<<1;
			if(x>i*n+1&&x<(i+1)&n)
			cout<<i+1<<" "<<x-i*n-1;
		}
	}
	return 0;
}