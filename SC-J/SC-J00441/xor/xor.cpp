#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,answr;
void dfs(int i,int sum,int ans,bool f)//f:是否为第一个数
{
	answr=max(answr,ans);
	if(i>n)return ;
	if(f==1)
	{
		if(a[i]==k)
		{
			dfs(i+1,a[i],ans+1,1);
		}
		else
		{
			dfs(i+1,a[i],ans,0);
		}
		dfs(i+1,0,ans,1);
	}
	else
	{
		if((sum^a[i])==k)
		{
			dfs(i+1,sum^a[i],ans+1,1);
		}
		else
		{
			dfs(i+1,sum^a[i],ans,0);
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	dfs(1,0,0,1);
	printf("%d",answr);
	return 0;
}