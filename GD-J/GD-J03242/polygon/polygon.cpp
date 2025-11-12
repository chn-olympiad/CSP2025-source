#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=998244353;
ll ans,k,sum;
int v[5010],c[5010],maxx=-1,ma=-1;

int a,b;
int check(int s,int g)
{
	if(s>(g<<1))  return 1;
	else  return 0;  
}
void dfs(int x,int y)
{
	if(y==a)
	{
		ans+=check(sum,ma);
		return;
	}
	for(int i=x+1;i<=b;i++)
	{
		c[y+1]=i;
		sum+=v[i];
		if(y==a-1)
		{
			ma=v[i];
		}  
		dfs(i,y+1);
		c[y+1]=0,sum-=v[i];
	}
}
void C(int n,int m)
{
	for(int i=1;i<=m-n+1;i++)
	{
		c[1]=i,sum=v[i];
		dfs(i,1);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&v[i]);
		maxx=max(maxx,v[i]);
	}  
	if(maxx==1)
	{
		printf("%lld",k%N);
		return 0;
	}
	sort(v+1,v+k+1);
	b=k;
	for(a=3;a<=b;a++)
	{
		C(a,b);
		memset(c,0,sizeof(c));
	}  
	printf("%lld",ans%N);
	return 0;
}
