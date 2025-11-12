#include<bits/stdc++.h>
using namespace std;

int n,m;
int c=0,r=0;
int gad[105]={};
int plc[15][15]={};

int cmp(int u,int v)
{
	return u>v;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>gad[i];
	}
	int R=gad[1];
	sort(gad+1,gad+1+n*m,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			plc[i][j]=0;
		}
	}
	
	int k=1;
	int i=1,j=1;
	plc[1][1]=gad[k];
	
	while(k<n*m)
	{
		while(plc[i+1][j]==0 && i+1<=n)
		{
			i++;
			k++;
			plc[i][j]=gad[k];
		}
		if(plc[i][j+1]==0 && j+1<=m && k<=n*m)
		{
			j++;
			k++;
			plc[i][j]=gad[k];
		}
		while(plc[i-1][j]==0 && i-1>=1)
		{
			i--;
			k++;
			plc[i][j]=gad[k];
		}
		if(plc[i][j+1]==0 && j+1<=m && k<=n*m)
		{
			j++;
			k++;
			plc[i][j]=gad[k];
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(plc[i][j]==R)
			{
				c=j;
				r=i;
			}
		}
	}
	cout<<c<<' '<<r;
	return 0;
}

