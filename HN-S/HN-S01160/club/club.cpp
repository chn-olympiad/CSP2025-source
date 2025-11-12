#include<iostream>
#include<cstdio>
using namespace std;
int s1=0,s2=0,s3=0;
long long MAX=0;
int a[100000][4],ZW[10000000],DH[1000000];
int main()
{	int t;
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int q=1;q<=t;q++)
	{	int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i][1]);
			scanf("%d",&a[i][2]);
			scanf("%d",&a[i][3]);
			int MS=a[i][1];
			ZW[i]=1;
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]>MS) ZW[i]=j;
			}
			
		}
		for(int x=1;x<=n;x++)
		{	
			if(ZW[x]=1)
			{
				if(s1<=n/2)
				{
				MAX+=a[x][1];
				s1++;
				}
				else DH[x]=1;
			}
			if(ZW[x]=2)
			{
				if(s2<=n/2){
				s2++;
				MAX+=a[x][2];
				
				}
				else DH[x]=2;
			}
			if(ZW[x]=3)
			{
				if(s3<=n/2){
				s3++;
				MAX+=a[x][3];
				
				}
				else DH[x]=3;
			}
		}
		for(int d=1;d<=n;d++)
		{
			if(DH[d]=1)
			{
				if(a[d][2]>a[d][3])
				{
					MAX+=a[d][2];
				}
				else MAX+=a[d][3];
			}
			if(DH[d]=2)
			{
				if(a[d][1]>a[d][3])
				{
					MAX+=a[d][1];
				}
				else MAX+=a[d][3];
			}
			if(DH[d]=3)
			{
				if(a[d][2]>a[d][1])
				{
					MAX+=a[d][2];
				}
				else MAX+=a[d][1];
			}
			
		}
		printf("%d\n",MAX);
		MAX=0;
		n=0;
		for (int r=1;r<=n;r++)
		{
		for(int i=1;i<=3;i++)
		{
			a[r][i]=0;
		}
		ZW[r]=0;
		DH[r]=0;
		
		}
	}
	return 0;
}
