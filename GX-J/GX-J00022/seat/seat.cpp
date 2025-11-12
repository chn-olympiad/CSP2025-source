#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<stdio.h>
using namespace std;
int n,m,cnt=0;
int r=0;
int u=0,v=0;
int a[2010][2010];
int k[200010];
bool  sort(int x,int y)
{
	if(x>y)
		return x>y;
	else
		return y>x;
}
int main()
{
		freopen("seat.in","r",stdin);
		freopen("seat.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[n][m];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				cnt++;
				k[cnt]=a[i][j];
			}
		sort(k+1,k+cnt+1);
		for(int i=1;i<=cnt;i++)
			if(k[i]==a[1][1])
					r=i;
		cout<<r/m<<" "<<r%m;
		return 0;
}
