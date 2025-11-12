#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
bool cmp(int a,int b)
{
	return a>b;
}
int r;
int a[50][50];
int ma[1005];
int main()
{
	freopen("seat","r",stdin);
	freopen("seat","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=m*n;i++)
	{
		cin >>ma[i];
	}
	r = ma[1];
	bool flag = 0;
	int t = 0;
	sort(ma+1,ma+1+n*m,cmp);
	for(int i = 1;i<=m;i++)
	{
		if(flag == 0)
		{
			for(int j = 1;j<=n;j++)
			{
				t++;
				a[j][i] = ma[t];
				flag = 1;
			}
		} 
		else
		{
			for(int j= n;j>=1;j--)
			{
				t++;
				a[j][i] = ma[t];
				flag = 0;
			}
		}
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			if(a[i][j] == r)cout << j<<' '<<i;
		}
	}
	return 0;
} 
