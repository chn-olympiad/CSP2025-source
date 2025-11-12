#include <bits/stdc++.h>
using namespace std;
int a[144];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	
	int sud=a[1],be=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int x=0;
		for(int j=1;j<=n;j++)
		{
			if(a[be]==sud)
			{
				cout<<i<<' '<<j;
				x=1;
				break;
			}
			be++;
		}
		if(x) break;
		i++;
		for(int j=n;j>=1;j--)
		{
			if(a[be]==sud)
			{
				cout<<i<<' '<<j;
				x=1;
				break;
			}
			be++;
		}
		if(x) break;
	}
	
	return 0;
}