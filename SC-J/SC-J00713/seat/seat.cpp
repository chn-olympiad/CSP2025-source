#include<bits/stdc++.h>
using namespace std;

int cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int w=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==w)
		{
			cout<<x<<" "<<y;
			return 0;
		}
		if(x%2&&y<n)
		{
			y++;
			continue;
		}
		else if(x%2&&y==n) 
		{
			x++;
			continue;
		}
		else if(x%2==0&&y>1)
		{
			y--;
			continue;
		}
		else if(x%2==0&&y==1)
		{
			x++;
			continue;
		}
	}
	return 0;
}