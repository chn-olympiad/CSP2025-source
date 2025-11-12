#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
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
	int b=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(b==a[i])
		b=i;
	}
	int i=(b-1)/n+1;
	int j;
	if(i%2==1)
	{
		j=(b-1)%n+1;
	}
	if(i%2==0)
	{
		j=n*i+1-b;
	}
	cout<<i<<" "<<j;
	return 0;
}
