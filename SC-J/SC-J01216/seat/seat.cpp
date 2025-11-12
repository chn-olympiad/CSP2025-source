#include <bits/stdc++.h>
using namespace std;

int n,m,b[105][105],a[205];

bool cmp(int x,int y)
{
	return x > y; 
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
		cin >> a[i];
	int c = a[1];
	
	sort(a + 1,a + n * m + 1,cmp);
	
	int cnt = 1;
	for(int i = 1;i <= n;i++)
	{
		if(i % 2 == 0)
		{
			for(int j = m;j >= 1;j--)
			{
				b[j][i] = a[cnt];
				cnt++; 
			}	
		}
		else
		{
			for(int j = 1;j <= m;j++)
			{
				b[j][i] = a[cnt]; 
				cnt++;
			}	
		}
	}
	
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			if(b[j][i] == c)
			{
				cout << i << " " << j;	
				return 0;	
			}
	return 0;
} 