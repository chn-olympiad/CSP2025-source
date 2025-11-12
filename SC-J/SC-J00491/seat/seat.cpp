#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],x,c,d,l,r,r1;
bool cmp(int q,int w)
{
	return q>w;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	c=2*n;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			d=i;
			break;
		}
	}
	l=d/c;
	r=d%c;
	l*=2;
	l++;
	if(r==0||r>n)
	{
		l++;
		if(r==0)
		{
			cout<<l<<" "<<1;
		}else
		{
			r-=n;
			cout<<l<<" "<<n-(r-1);
		}
	}else
	{
		cout<<l<<" "<<r;
	}
	return 0;
}