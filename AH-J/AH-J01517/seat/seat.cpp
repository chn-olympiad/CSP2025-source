#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int d;
int a[505];
bool cmp(int aa,int bb)
{
	return aa>bb;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	d=-1;
	int x=1,y=1,i=1;
	if(n==1)
	{
		for(int i=1;i<=m;i++)
			if(a[i]==r)
			{
				cout<<i<<" "<<1;
				return 0;
			}
	}
	for(;;)
	{
		if(a[i]==r) 
		{
			cout<<x<<" "<<y;
			return 0;
		}
		i++;
		if(d==-1&&y==n)
		{
			x++;
			if(a[i]==r) 
			{
				cout<<x<<" "<<y;
				return 0;
			}
			i++;
			d=1;
		}
		else if(d==1&&y==1)
		{
			x++;
			if(a[i]==r) 
			{
				cout<<x<<" "<<y;
				return 0;
			}
			i++;
			d=-1;
		}
		if(d==-1) y++;
		else y--;
	}
	return 0;
}
