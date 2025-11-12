#include <bits/stdc++.h>
using namespace std;
int a[500005]={},n,maxn=0,k=0,cd[500005]={};
void dfs(int step,int yhh,int num,int sum)
{
	
	if(num==n)
	{
		if(sum>maxn)
		{
			maxn=sum;
		}
		return ;
	}
	for(int i=num+1;i<=num+cd[step];i++)
	{
		yhh=yhh^a[i];
		if(yhh==k)
		{
			sum++;
			cd[step]=i-num;
			yhh=0;
		}
		dfs(step+1,yhh,i,sum);
		
	}
	return ;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cd[i]=n;
	}
	dfs(1,0,0,0);
	cout<<maxn;
	return 0;
}
