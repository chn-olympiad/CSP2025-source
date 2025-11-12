#include<cstdio>
#include<algorithm>
using namespace std;
int m,n;
int a[1000];
int z[20][20];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	int s1=a[1],cnt=0;
	sort(a+1,a+1+n*m);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
		  for(int j=1;j<=n;j++)
		  {
		  	 z[i][j]=a[n*m-cnt];
		  	 cnt++;
		  }
	    }  
		if(i%2==0) 
		{
			for(int j=n;j>=1;j--)
			{
				z[i][j]=a[n*m-cnt];
				cnt++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(z[i][j]==s1) 
			{
				printf("%d %d",i,j);
				return 0;
			}
		}
	}
	return 0;
}
