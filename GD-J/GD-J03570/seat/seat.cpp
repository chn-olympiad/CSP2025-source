#include <bits/stdc++.h>
using namespace std;

int f[100001];
int f12[100][100];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> f[i];
	}
	int a=f[1],abc;
	sort(f+1,f+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(f[i]==a)
		{
			abc=i;
			break;
		}
	}
	int x=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f12[i][j]=x;
			if(x==abc)
			{
				cout << i << " " << j;
				return 0;
			}
			x++;
		}
		i++;
		for(int j=n;j>=1;j--)
		{
			f12[i][j]=x;
			if(x==abc)
			{
				cout << i << " " << j;
				return 0;
			}
			x++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
