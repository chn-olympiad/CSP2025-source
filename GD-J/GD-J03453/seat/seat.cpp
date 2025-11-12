#include <bits/stdc++.h>
using namespace std;
int s[11][11];
int p[121];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int i,j;
	int x;
	for(i=1;i<=n*m;i++)
	{
		cin>>p[i];
		if(i==1) x=p[i];
	}
	int step=0;
	sort(p+1,p+1+n*m,cmp);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			step++;
			s[i][j]=p[step];
			if(s[i][j]==x)
			{
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	return 0;
}
