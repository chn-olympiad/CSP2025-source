#include<bits/stdc++.h>
using namespace std;
long a[111];
int find(int tmp,int sum)
{
	for(int i=1;i<=sum;i++)
	{
		if(a[i]==tmp)
		{
			return i;
		}
	}
	return 1;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cmp;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	cmp=a[1];
	sort(a+1,a+n*m+1);
	cmp=find(cmp,n*m);
	int x=1,y=1;
	int t=0;
	for(int i=1;i<=n*m-cmp;i++)
	{
		y+=t;
		if(y>n)
		{
			y--;
			t=-1;
			x++;
		}
		if(y<1)
		{
			y++;
			t=1;
			x++;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
