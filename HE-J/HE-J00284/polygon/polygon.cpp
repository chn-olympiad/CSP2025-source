#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
long long mod=998244353;
long long a[50010];
bool P(long long b[],long long t)
{
	long long sum=0,maxx=-1;
	for(int i=1;i<=t;i++)
	{
		sum+=b[i];
		maxx=max(b[i],maxx);
	}
	if(2*maxx>sum)
	{
		return 1;
	}
	return 0;
}
void dfs(long long s,int c,int t)
{
	if(s=s-c)
	{
		return ;
	}
    else
    {
    	long long b[50010];
     	for(int j=s;j<=n;j++)
    	{
    		b[t]=a[j];
    		if(t==c)
    		{
    			if(P(b,c))
     		   	{
    		   		ans++;
		    	}
			}
			dfs(s+1,c,t+1);
     	}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		dfs(1,i,1);
	}
	if(n==3)
	{
		if((a[1]<(a[2]+a[3]))&&(a[2]<(a[1]+a[3]))&&(a[3]<(a[1]+a[2])))
		{
			cout<<1%mod;
			return 0;
		}
        else
        {
        	cout<<0%mod;
        	return 0;
		}
	}
	else
	{
		cout<<ans;
	}
	return 0;
}
