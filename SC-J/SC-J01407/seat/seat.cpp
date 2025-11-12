#include<bits/stdc++.h>
using namespace std;
long long a[188];
long long rq[188];//倒序a[i]
long long jsq=0,rqgs=0;
long long zw[15][15];
bool flag=0;//0:从上往下  1:从下往上 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	for(long long i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	int R=a[1];
    sort(a+1,a+1+n*m);
	for(long long i=n*m;i>=1;i--)
	{
		jsq++;
		rq[jsq]=a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		if(flag==0)
		{
		    for(long long j=1;j<=m;j++)
		    {
		    	rqgs++;
		    	zw[j][i]=rq[rqgs];
			}
			flag=1;
		}
		else if(flag==1)
		{
		    for(long long j=m;j>=1;j--)
		    {
		    	rqgs++;
		    	zw[j][i]=rq[rqgs];
			}
			flag=0;
		}
	}
	for(long long i=1;i<=m;i++)
	{
		for(long long j=1;j<=n;j++)
		{
			if(zw[i][j]==R)
			{
				printf("%d ",j);
				printf("%d",i);
				return 0;
			}
		}
	}
	return 0;
}