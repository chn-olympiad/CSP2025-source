#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int fi[10001][5005];
int dis[1000001],n,num,a[1000001],ans=0,ans1=0,ans2=0,cont=0;
void dfs(int x,int f)
{
	if(x>num)
	{
		if(cont>ans*2&&ans!=0&&fi[cont][ans]==0)
		{
			ans1+=1;
			fi[cont][ans]=1;
			ans1%=998244353;
		}
		cont=0;
		ans=0;
//		cout<<endl;
		return ;
	}
	for(int i=1;i<=f;i++)
	{
		if(dis[i]==0)
		{
			cont+=i;
			ans++;
//			cout<<i<<" ";
			dis[i]=1;
			dfs(x+1,f);			
			dis[i]=0;
		}

	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			sum++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		num=i;
		dfs(1,n);
	}
	cout<<(ans1%998244353-sum)/2;
}
