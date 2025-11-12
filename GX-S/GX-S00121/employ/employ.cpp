#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define maxn 505
#define mod 998244353
using namespace std;

int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!('0'<=c && c<='9'))
	{
		if(c=='-')
		  f=-1;
		c=getchar();
	}
	while('0'<=c && c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

int n,m,k,cnt;
char s[maxn];
int c[maxn];
int main()
{
	freopen("employ3.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	scanf("%s\n",s+1);
	for(int i=1;i<=n;i++)
	   if(s[i]=='0')
	      ++cnt;
	for(int i=1;i<=n;i++)
	{
	   c[i]=read();
	   if(c[i]==0)
	     k++;
	}
	if(n==m)
	{
		for(int i=1;i<=n;i++)
		   if(s[i]=='0')
		   {
			  printf("0\n");
			  return 0; 
		   }
		long long sum=1;
		for(int i=n;i>1;i--)
		   sum=(sum*i)%mod;
		printf("%lld\n",sum);
		return 0;
	}
	if(cnt==n)
	{
		if(m==0)
		{
			long long sum=1;
		    for(int i=n;i>1;i--)
		       sum=(sum*i)%mod;
		    printf("%lld\n",sum);
		}
		else
		    printf("0\n");
		return 0;
	}
	if(cnt==0)
	{
		long long sum=1;
	    for(int i=2;i<=n;i++)
		    sum=(sum*i)%mod;
	    printf("%lld\n",sum);
	    return 0;
	}
	if(m==1)
	{
		int t=n+1,lst=0,num=0;
		for(int i=1;i<=n;i++)
		   if(s[i]=='1')
		   {
			   t=min(t,i-lst);
			   lst=i;
		   }
		for(int i=1;i<=n;i++)
		   if(c[i]>t || c[i]==t)
		      ++num;
		if(num==0)
		  printf("0\n");
		else
		{
			long long sum=1;
		    for(int i=n-num;i>1;i--)
		       sum=(sum*i)%mod;
		    sum=(sum*num)%mod;
		    printf("%lld\n",sum);
		}
		return 0;
	}
	printf("0\n");
	
	return 0;
}
