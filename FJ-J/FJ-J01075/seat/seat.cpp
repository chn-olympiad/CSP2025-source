#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn];
int t[maxn][maxn];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int l=0;
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				t[i][j]=a[++l];
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				t[i][j]=a[++l];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(t[i][j]==r)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}

