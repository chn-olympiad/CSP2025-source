#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,seat[15][15]={0},sco[105]={0},max,me;
	cin >> n >>m;
	cin >> sco[1];
	me = sco[1];
	for(int i=2;i<=n*m;i++)
	{
		cin >> sco[i];
	}
	
	for(int j=1;j<n*m;j++)
	{
		for(int i=n*m;i>=2;i--)
		{
			if (sco[i]>sco[i-1])
			{
				max = sco[i];
				sco[i]= sco[i-1];
				sco[i-1]= max;
			}
			
		}
	}
	int a=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			seat[i][j] = sco[a];
			if (sco[a]==me)
			{
				cout << i << " " << j;
				return 0;
			}
			a+=1;
		}
	}
	
	
	return 0;
}
