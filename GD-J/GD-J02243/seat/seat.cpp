#include<bits/stdc++.h>
using namespace std;

int n,m;
int DIGI=0;
int mark=0;
int num[1000];
int a[11][11];

void swapt(int x)
{
	for(int i=1;i<=x-1;i++)
		for(int j=i+1;j<=x;j++)
			if(num[j]>num[i])
			{
				int t=num[j];
				num[j]=num[i];
				num[i]=t;	
			} 
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>num[i];
	int c=num[1];
	swapt(n*m);
	for(int i=1;i<=m;i++)
	{
		if(mark==0)
		{
			mark=1;
			for(int j=1;j<=n;j++) 
			{
				DIGI++;
				a[j][i]=num[DIGI];
				if(num[DIGI]==c)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		if(mark==1)
		{
			mark=0;
			for(int j=n;j>=1;j--) 
			{
				DIGI++;
				a[j][i]=num[DIGI];
				if(num[DIGI]==c)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
