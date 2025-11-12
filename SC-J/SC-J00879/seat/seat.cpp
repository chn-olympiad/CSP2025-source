#include<bits/stdc++.h>
using namespace std;
long long n,m,mc,r,c,a[110],f;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	f=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==f)
		{
			mc=i;
			break;
		}
	}
	r=mc/n+1;
	if(r%2==0)
	{
		c=n-mc%n;
	}
	else
	{
		c=mc%n+1;
	}
	cout<<r<<" "<<c;
	return 0;
}
