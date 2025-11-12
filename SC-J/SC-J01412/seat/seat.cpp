#include <bits/stdc++.h>
using namespace std;

int n,m,p;
int a[15][15],b[105];

bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int sum = n*m;
	for(int i = 1;i <= sum;i++) cin >> b[i];
	p = b[1];
	sort(b+1,b+n*m+1,cmp);
	
	int cnt = 1;
	for(int i = 1;i <= m;i++)
	{
		if(i%2 == 1)
		{
			for(int j = 1;j <= n;j++)
			{
				a[j][i] = b[cnt];
				cnt++;
			}
		}
		else
		{
			for(int j = n;j >= 1;j--)
			{
				a[j][i] = b[cnt];
				cnt++;
			}
		}
	}
	
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			if(a[i][j] == p)
				cout << j << ' ' << i;
	return 0;
}