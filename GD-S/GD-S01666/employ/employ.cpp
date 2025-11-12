#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
char s1;
int s[505];
int c[505];
int a[505]; //面试顺序表 
int a1;
bool b[505];
int t1;
long long ans;
void dfs(int step)
{
	if(step>n) //选完，检验可行性 
	{
		int t=n-t1;
		for(int i=1; i<=n; ++i)
		{
			if((n-t)>=a[i] || s[i]==0) //无法通过 
				--t;
		}
		if(t>=m)
			++ans;
		return;
	}
	for(int i=1; i<=n; ++i)
	{
		if(!b[i])
		{
			b[i]=true;
			a[++a1]=c[i];
			dfs(step+1);
			--a1;
			b[i]=false;
		}
	}
}
long long tp()
{
	for(int i=1; i<=n; ++i)
	{
		if(s[i]!=1)
			return 0;
	}
	
	if(n-t1<m)
		return 0;
	//A 5 5
	long long t=1;
	for(int i=n; i>=2; --i)
	{
		t*=i;
		t=t%998244353;
	}
	return t;
	
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	s1=getchar();
	for(int i=1; i<=n; ++i)
	{
		s1=getchar();
		s[i]=s1-'0';
	}
	for(int i=1; i<=n; ++i)
	{
		scanf("%d",&c[i]);
		if(c[i]==0)
			++t1;
	}
	ans=tp();
	if(ans!=0)
	{
		printf("%d",ans);
		return 0;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
