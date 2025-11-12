#include<bits/stdc++.h>
using namespace std;
bool cmp(int y, int x)
{
	return y>x;
}
int a[105];
int b[11][11];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,f;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
	{
		cin>>a[i];
		if(i==1)
		{
			f=a[i];
		}
	}
	int s=0;
	int l=n*m;
	sort(a+1,a+l+1,cmp);
	for(int j=1; j<=m; j++)
	{
		if(j%2==0)
		{
			for(int i=n; i>=1; i--)
			{
				s++;
				b[i][j]=a[s];
			}
		}
		else if(j%2==1)
		{
			for(int i=1; i<=n; i++)
			{
				s++;
				b[i][j]=a[s];
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(b[i][j]==f)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}
