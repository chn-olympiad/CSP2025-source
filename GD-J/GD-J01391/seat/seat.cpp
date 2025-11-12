#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],w,t=0;
bool bdx(int x,int y)
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
	w=a[1];
	sort(a+1,a+1+n*m,bdx);
	for(int i=1;i<=m;i++)
	{
		int j;
		if(i%2==1)
		{
			j=1;
		}
		else if(i%2==0)
		{
			j=n;
		}
		for(;j>=1&&j<=n;)
		{
			if(a[++t]==w)
			{
				cout<<i<<" "<<j;
				return 0;
			}
			if(i%2==1)
			{
				j++;
			}
			else if(i%2==0)
			{
				j--;
			}
		}
	}
	return 0;
}
