#include<cstdio>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int a[n*m];
	int seat[n*m]={0};
	int i1=1;
	for(int i=0;i<n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	int jspx[105]={0};
	for(int k=0;k<n*m;k++)
	{
		jspx[a[k]]++;
	}
	for(int j=1;j<=100;j++)
	{
		if(jspx[j]!=0)
		{
			//printf("%d ",j);
			seat[i1]=j;
			printf("%d ",seat[i1]);
			i1++;
			
		}
	}
	for(int o=1;o<=i1;o++)
	{
		if(a[0]==seat[o])
		{
		
			//printf("%d %d ",seat[o],o);
			//o=n*m-o+1;
			printf("%d ",o);
			if(o%n==0)
			{
				if(o/n%2==1)
				{
					printf("%d %d",m-o/n+1,n);
				}
				else
				{
					printf("%d %d",m-o/n+1,1);
				}
			}
			else
			{
				if(o/n%2==1)
				{
					printf("%d %d",m-o/n,n-o%n+1);
				}
				else
				{
					printf("%d %d",m-o/n,o%n);
				}
			}
			break;
		}
	}
	
}
