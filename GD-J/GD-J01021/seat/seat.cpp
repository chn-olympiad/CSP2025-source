#include<bits/stdc++.h>
using namespace std;
int n,m,s,a[1001],res,r,c;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==s) res=i;
	}
	r=res/n;
	if (res%n) r++;
	if (r%2!=0)
	{
		c=(res-1)%n+1;
	}
	else
	{
		c=n-(res-1)%n;
	}
	cout<<r<<" "<<c;
	return 0;
}
