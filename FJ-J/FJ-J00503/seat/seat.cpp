#include<bits/stdc++.h>
using namespace std;
int num[100];
int a[10][10];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,m,k;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>num[i];
	}
	k=num[1];
	sort(num+1,num+m*n+1,cmp);
	int x=1,y=1,s=1;
	while (s<=n*m)
	{
		if (y%2!=0)
		{
			if (x<=n)
			{
				a[x][y]=num[s];
				x++;
			}
			else
			{
				s-=1;
				x=n;
				y+=1;
			}
		}
		else
		{
			if (x>=1)
			{
				a[x][y]=num[s];
				x--;
			}
			else
			{
				s-=1;
				x=1;
				y+=1;
			}
		}
		s++;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (a[i][j]==k)
			{
				cout<<j<<" "<<i;
			}
		}
		cout<<endl;
	}
}
