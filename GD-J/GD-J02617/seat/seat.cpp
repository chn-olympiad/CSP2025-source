#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],b[100][100];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> a[1];
	int R = a[1];
	for(int i = 2;i<=n*m;i++)
	{ 
		cin >> a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int l=1,h=1;
	bool dt=true;
	for(int i = 1;i<=n*m;i++)
	{
		b[h][l] = a[i];
		if(h<=m&&dt) h++;
		else h--;
		if(h>m) h=m,l++,dt=false;
		if(h<1) h=1,l++,dt=true;
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			if(b[i][j]==R)
			{
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}
