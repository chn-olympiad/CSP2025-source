#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#include<map>
#include<vector>
using namespace std;

int t,n;
struct nn
{
  int sum,id;	
}a[1000001],b[1000001],c[1000001],d[1000001];
bool gz(nn xe,nn ye)
{
  return xe.sum<ye.sum;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
	  scanf("%d",&n);
	  int tot_a=0,tot_b=0,tot_c=0,sum=0;
	  for(int i=1;i<=n;i++)
	  {
	    scanf("%d %d %d",&a[i].sum,&b[i].sum,&c[i].sum);
	    if(a[i].sum>=b[i].sum&&a[i].sum>=c[i].sum)
	      tot_a++,sum+=a[i].sum;
	    else
	    {
		  if(b[i].sum>=a[i].sum&&b[i].sum>=c[i].sum)
	        tot_b++,sum+=b[i].sum;
	      else
	      { 
	        if(c[i].sum>=b[i].sum&&c[i].sum>=a[i].sum)
	          tot_c++,sum+=c[i].sum;
	      }
		}
	      
	  }
	  if(tot_a<=n/2&&tot_b<=n/2&&tot_c<=n/2)
	  {
		printf("%d\n",sum);
		continue;
	  }
	  if(tot_a>n/2)
	  {
		sum=0;
		for(int i=1;i<=n;i++)
		  d[i].sum=a[i].sum-max(b[i].sum,c[i].sum),sum+=a[i].sum;
		sort(d+1,d+n+1,gz);
		for(int i=1;i<=n/2;i++)
		  sum=sum-d[i].sum;
		printf("%d\n",sum);
	  }
	  if(tot_b>n/2)
	  {
		sum=0;
		for(int i=1;i<=n;i++)
		  d[i].sum=b[i].sum-max(a[i].sum,c[i].sum),sum+=b[i].sum;
		sort(d+1,d+n+1,gz);
		for(int i=1;i<=n/2;i++)
		  sum=sum-d[i].sum;
		printf("%d\n",sum);
		continue;
	  }
	  if(tot_c>n/2)
	  {
		sum=0;
		for(int i=1;i<=n;i++)
		  d[i].sum=c[i].sum-max(b[i].sum,a[i].sum),sum+=c[i].sum;
		sort(d+1,d+n+1,gz);
		for(int i=1;i<=n/2;i++)
		  sum=sum-d[i].sum;
		printf("%d\n",sum);
		continue;
	  }
	}
	return 0;
}
