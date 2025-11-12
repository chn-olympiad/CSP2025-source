#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],l=1,b[105],s;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			b[l]=a[i][j];
			l++;
		}
	}
	sort(b+1,b+l+1,cmp);
	for (int i=1;i<=l;i++)
	{
		if(b[i]==a[1][1])
		{
			s=i;
			break;
		}
	}
	int c=0,r=0,d=0;
	if(s%n!=0)
	{
		c=s/n+1;
	}
	else
	{
		c=s/n;
	}
	d=s-(c-1)*n;
	if(c%2==0){
		r=n-d+1;
	}
	else
	{
		r=d;
	}
	cout<<c<<" "<<r;
	return 0;
}
