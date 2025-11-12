#include<bits/stdc++.h>
using namespace std;

int n,m,a[1001],ing,b=1,s[1001][1001],v=1;
bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	ing=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>ing) b++;
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2)
		{
			for(int j=1;j<=n;j++)
			{
				s[i][j]=a[v];
				if(v==b) cout<<i<<" "<<j;
				v++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				s[i][j]=a[v];
				if(v==b) cout<<i<<" "<<j;
				v++;
			}
		}
	}
	return 0;
}
