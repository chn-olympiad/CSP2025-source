#include <bits/stdc++.h>

using namespace std;

//seat.cpp

int n,m;
int a[101];
int seat[11][11];

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= (n * m);i ++)
	{
		cin >> a[i];
	}
	
	int x = a[1];
	sort(a + 1,a + (n * m) + 1,cmp);
	
	int cnt = 0;
	for(int i = 1;i <= n;i ++)
	{
		if(i % 2 == 1)
		{
			for(int j = 1;j <= m;j ++)
			{
				seat[i][j] = a[++ cnt];
			}
		}
		else
		{
			for(int j = m;j >= 1;j --)
			{
				seat[i][j] = a[++ cnt];
			}
		}
	}
	
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= m;j ++)
		{
			if(seat[i][j] == x){
				cout << i << ' ' << j;
				return 0;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
