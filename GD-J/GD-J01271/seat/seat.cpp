#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int a[11][11];
int b[102];
int comp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n*m ; i++)
	{
		scanf("%d",&b[i]);
	}
	int te=b[1];
	int cnt=0;
	sort(b+1,b+n*m+1,comp);
	for(int j = 1 ; j <= m ; j++)
	{
		if(j%2==1)
		{
			for(int i = 1 ; i <= n ; i++)
			{
				a[i][j]=b[++cnt];
				if(a[i][j]==te)
				{
					printf("%d %d",j,i);
					return 0;
				}
			}
		}
		else
		{
			for(int i = n ; i >= 1 ; i--)
			{
				a[i][j]=b[++cnt];
				if(a[i][j]==te)
				{
					printf("%d %d",j,i);
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
