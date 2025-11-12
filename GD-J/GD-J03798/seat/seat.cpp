#include <bits/stdc++.h>
using namespace std;
int n,m;
int fenshu;
int f[150];
int a[15][15];
int t;

bool cmp(int x,int y)
{
	if (x>y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int ren=n*m;
	for (int i=1;i<=ren;i++)
	{
		cin>>f[i];
	} 
	fenshu=f[1];
	sort(f+1,f+1+ren,cmp);
	t=1;
	
	
	for (int i=1;i<=m;i++)//i循环列数 
	{
		if (i%2==1)
		{
			for (int j=1;j<=n;j++)//j循环行数，当i为单数时正序循环 
			{
				a[j][i]=f[t];
				t++;			
			}
		}
		else if (i%2==0)
		{
			for (int j=n;j>=1;j--)//j循环行数，当j为双数时逆序循环 
			{
				a[j][i]=f[t];
				t++;
			}
		}
	}
	
	
	for (int i=1;i<=n;i++)//循环行数 
	{
		for (int j=1;j<=m;j++)//循环列数 
		{
			if (a[i][j]==fenshu)
			{
				cout<<j<<' '<<i;
			}
		}
	}
	return 0;
 } 
