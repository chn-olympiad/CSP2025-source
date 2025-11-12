#include<bits/stdc++.h>
using namespace std;
int n,m,a[102],b,b1;
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
		if(i==1) b=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==b)
		{
			b1=i;
			break;
		}
	}
	int lie=(b1-1)/n+1,hang=b1-b1/n*n;
	if(hang==0) hang=n;
	if(lie%2==0) hang=n-hang+1;
	cout<<lie<<" "<<hang;
	return 0;
}
/*
略一眼
我们先寻找小明的排名，再通过排名找位置。
小明在第i%n列。若列为奇数，则行为 i-i/n*n(若为0，则为n)
否则行为n+1-列为奇数下的行。 
*/ 