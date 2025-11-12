#include <bits/stdc++.h>
using namespace std;
int n,m,a[20][20],j=1,i=1,s[400],f=1,sum;
bool l=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=m*n;
	for(int i=1;i<=t;i++) cin>>s[i];
	int x=s[1];
	sort(s+1,s+t+1,cmp);
	t=m;
	while(t--)
	{
		
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				a[i][j]=s[f];
				f++;
			}
		}else
		{
			for(int i=n;i>=1;i--)
			{
				a[i][j]=s[f];
				f++;
			}
		}
		j++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==x)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
