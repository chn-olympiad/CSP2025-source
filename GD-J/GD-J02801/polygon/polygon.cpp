#include<bits/stdc++.h>
using namespace std;
int n,sum;
int a[5005];
int b[5005];
bool v[5005];
bool xx(int c)
{
	int zd=0,s=0;
	for(int i=1;i<=c;i++)
	{
		zd=max(zd,b[i]);
		s+=b[i];
	}
	zd*=2;
	return s>zd;
}
void dfs(int t,int st)
{
	if(t>3&&xx(t-1))
	{
		sum+=1;
		sum%=998244353;
	}
	for(int i=st;i<=n;i++)
	{
		if(!v[i])
		{
			v[i]=true;
			b[t]=a[i];
			dfs(t+1,i+1);
			v[i]=false;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n>25)
	{
		cout<<0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	memset(v,false,sizeof(v));
	dfs(1,1);
	printf("%d",sum);
	return 0;
}
