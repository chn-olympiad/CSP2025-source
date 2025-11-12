#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r;
	scanf("%d%d",&c,&r);
	int a[c+1][r+1],zancun[c*r];
	for(int i=0;i<c*r;++i)
	{
		scanf("%d",&zancun[i]);
	}
	int R=zancun[0];
	sort(zancun,zancun+c*r);
	int k;
	k=c*r-1;
	for(int i=1;i<=c;i++)
	{
		for(int j=1;j<=r;j++)
		{
			a[i][j]=zancun[k];
			if(a[i][j]==R)
			{
				if(i%2==1)
					printf("%d %d",i,j);
				if(i%2==0)
					printf("%d %d",i,r+1-j);
				return 0;
			}
			--k;
		}
	}
	return 0;
}