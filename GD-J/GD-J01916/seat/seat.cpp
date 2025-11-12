#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int c[11][11];
int d[101];
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int gesp;
	
	for(int i=1;i<=n*m;i++)
	{
		cin>>d[i];
	}
	gesp=d[1];
	sort(d+1,d+n*m+1,cmp);
	
	int num=1;
	bool ccf=0;
	for(int i=1;i<=m;i++)
	{
		if(ccf==0)
		{
			ccf=1;
			for(int j=1;j<=n;j++)
			{
				c[j][i]=d[num];
				num++;
			}
		}
		else
		{
			ccf=0;
			for(int j=n;j>0;j--)
			{
				c[j][i]=d[num];
				num++;
			}
		}
	}
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			if(c[i][j]==gesp)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
		cout<<endl;
	}
	return 0;
}
