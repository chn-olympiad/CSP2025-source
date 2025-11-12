#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
bool cmp(int a,int b)
{
	if(a>b) return true;
	else return false;
}
int n,m,seat[110][110],gra[110],k=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>gra[i];
	}
	int x=gra[1];
	sort(gra+1,gra+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=n;j++)
			{
				seat[j][i]=gra[k];
				if(gra[k]==x)
				{
					cout<<i<<' '<<j;
					return 0;	
				} 
				k++;
			}
		}else
		{
			for(int j=n;j>=1;j--)
			{
				seat[j][i]=gra[k];
				if(gra[k]==x)
				{
					cout<<i<<' '<<j;
					return 0;	
				}
				k++;
			}
		}
	}
	return 0;
}
