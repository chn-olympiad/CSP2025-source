#include<bits/stdc++.h>
using namespace std;
int s[11][11],a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t=1,a1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n;i>=1;i--)
	{
		if(i%2==1)
		{
			for(int j=m;j>=1;j--)
			{
				s[j][i]=a[t];
				t++;
			}
		}
		else
		{
			for(int j=1;j<=m;j++)
			{
				s[j][i]=a[t];
				t++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]==a1)cout<<j<<" "<<i;
		}
	}
	return 0;
}