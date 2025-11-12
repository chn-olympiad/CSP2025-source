#include<bits/stdc++.h>
using namespace std;
int n,m;
int mp[15][15];
int s[200];
int x = 1,y = 1;
int cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n>> m;
	for(int i = 1;i<=n*m;i++) cin >> s[i];
	int R = s[1];
	sort(s+1,s+1+n*m,cmp);
	for(int i = 1;i<=n*m;i++)
	{
		mp[x][y] = s[i];
		if(x%2 == 1) 
		{
			if(y<n) y++;
			else x++;
		}
		else
		{
			if(y>1) y--;
			else x++;
		}
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			if(R == mp[i][j])
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
