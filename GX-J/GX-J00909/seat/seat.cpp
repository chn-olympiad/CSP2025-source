#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int m,n;
    scanf("%d%d",&n,&m);
    int luo[m+10][n+10];
    const int Q=m*n;
    int a[Q];
    for(int i=1;i<=Q;i++)
    {
			scanf("%d",&a[i]);
	}
	bool yu=true;
	int t=a[1];
	sort(a+1,a+1+n,cmp);
	if(a[1]!=t)yu=false;
	int cnt;
	if(yu)
	{
		printf("1 1");
		return 0;
	}
	else
	{
		for(int i=1;i<=Q;i++)
		{
			if(a[i]==t)
			{
				cnt=i;
				break;
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(m%2==0)
			{
				for(int j=n;j>=1;j--)
			    {
				    luo[i][j]=a[i];
			    }
			}
			else
			{
				for(int j=1;j<=n;j++)
			    {
				    luo[i][j]=a[i];
			    }
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(m%2!=0)
			{
				for(int j=1;j<=n;j++)
			    {
				    if(luo[i][j]==a[cnt])
			    	{
					    printf("%d %d",i,j);
					    return 0;
				    }
			    }
			 }
			 else
			 {
			     for(int j=n;j>=1;j--)
			     {
				     if(luo[i][j]==a[cnt])
				     {
					     printf("%d %d",i,j);
					     return 0;
				     }
			     }
			 }
		}
	}
    return 0;
}
