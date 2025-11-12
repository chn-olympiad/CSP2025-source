#include<bits/stdc++.h>
#define max_n 5005
using namespace std;
int n,k;
int a[max_n];
int sum[max_n];
int ck[max_n][max_n];
int ans=0;
bool p=true;
int vs[max_n];
void dfs(int t,int cnt)
{
	if(t>n)
	{
		return;
	}
	if(vs[t])
	{
		return;
	}
	for(int i=t;i<=n;i++)
	{
		if(ck[t][i]==k)
		{
			dfs(i+1,cnt+1);
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=a[i-1])
		{
			p=false;
		}
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			ck[i][j]=sum[j]^sum[i-1]; 
		}
	}
	if(k==0)
	{
	    if(p)
	    {
	    	ans=n/2;
	    	cout<<ans;
		    return 0;
		}
	}
	return 0;
}
