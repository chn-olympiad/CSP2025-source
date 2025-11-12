#include<bits/stdc++.h>
using namespace std;
long long a[101];
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,i,j,ans,x,y,sum;
	cin>>n>>m;
	sum=n*m;
	cin>>a[1];
	ans=a[1];
	for(i=2;i<=sum;i++)
		cin>>a[i];
	sort(a+1,a+sum+1,cmp);
	for(i=1;i<=sum;i++)
	{
		if(a[i]==ans)
			ans=i;
	}
	x=ans/n+1;
	if(ans%n==0) x--;
	cout<<x;
	if(x%2==1)
	{
		y=ans%n;
		if(y==0) y=n;
	}
	else
	{
		y=ans%n;
		if(y==0) y=n;
		y=n+1-y;
	}
	cout<<" "<<y;
	return 0;
}
