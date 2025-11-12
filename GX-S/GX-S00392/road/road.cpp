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

long long n,m,k,fa[1000001],sum,tot;
struct nn
{
  long long d,to,val;
}a[10000001];
bool gz(nn x,nn y)
{
  return x.val<y.val;
}
long long find(long long x)
{
  if(x==fa[x]) return x;
  return fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=1000000;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	  scanf("%lld %lld %lld",&a[i].d,&a[i].to,&a[i].val);
	tot=m;
	for(int i=1;i<=k;i++)
	{
      long long c=0,t=0;
	  scanf("%lld",&c);
	  a[++tot]=(nn){0,100000+i,c};
	  for(int j=1;j<=n;j++)
	  {
		scanf("%lld",&t);
		a[++tot]=(nn){100000+i,j,t};
	  }
	}
	sort(a+1,a+tot+1,gz);
	for(int i=1;i<=tot;i++)
	{
	  //printf("%d %d %d\n",a[i].d,a[i].to,a[i].val);
	  int dx=find(a[i].d),dy=find(a[i].to);
	  if(dx!=dy)
	  {
	    fa[dy]=dx,sum+=a[i].val;
	  }
	  /*if(answer==k+n+1)
	    break;*/
	}
	printf("%lld",sum);
	return 0;
}
