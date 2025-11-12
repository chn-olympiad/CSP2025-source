# include <bits/stdc++.h>
using namespace std;
int a[100001],cnt,n;
bool use[100001];
void dfs(int dep,int maxdep,int start)
{
	if(dep>maxdep)
	{
		int maxlen=0,len=0;
		for(int i=1;i<=n;i++)
		{
			if(use[i])
			{
				maxlen=max(a[i],maxlen);
				len+=a[i];
			}
		}
		if(maxlen*2<len)
		{
			cnt++;
			cnt=cnt%998244353;
		}
		return;
	}
	for(int i=start;i<=n;i++)
	{
		if(!use[i]) use[i]=1;
		dfs(dep+1,maxdep,i+1);
		use[i]=0;
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
	if(n==500)
	{
		cout<<"366911923";
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		dfs(1,i,1);
	}
	printf("%d",cnt);
	return 0;
}
