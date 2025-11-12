#include <bits/stdc++.h>
using namespace std;

const int N=101;
int n,m,s[N],l,p,data,c,r;
bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","cin",stdin);
	freopen("seat.out","cin",stdout);
	cin>>n>>m;
	l=n*m;
	for(int i=1;i<=l;i++)
	{
		int a;
		cin>>a;
		s[i]=a;
	}
	data=s[1];
	sort(s+1,s+l+1,cmp);
	for(p=1;p<=l;p++)
		if(s[p]==data)
			break;
	int x=p/n;
	int y=p%n;
	if(y==0)
	{
		c=x;
		if(x%2==1)
			r=n;
		else r=1;
	}
	else
	{
		c=x+1;
		if(x%2==1)
			r=n-y+1;
		else r=y;
	}
	cout<<c<<' '<<r;
	return 0;
}