#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[105];
int b[15][15];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n * m;i++)
	{
		cin>>a[i];
	}
	int R = a[1], cnt = 0;
	sort(a+1,a+m*n+1,cmp);
	for(int i = 1;i <= m;i++)
	{
		if(i % 2 != 0)
		{	
			for(int j = 1;j <= n;j++)
			{
				cnt++;
				b[j][i] = a[cnt];
			}
		}
		else
		{
			for(int j = n;j >= 1;j--)
			{
				cnt++;
				b[j][i] = a[cnt];
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			if(b[i][j] == R)
			{
				cout<<j<<" "<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
