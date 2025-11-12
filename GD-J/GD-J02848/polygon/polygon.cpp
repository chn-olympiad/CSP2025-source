#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int n,ans=0;
int a[1000010],b[1000010];
void dfs(int step,int lim,int ge,int num,int mx)
{
	
	if (ge==lim)
	{
		if (mx*2<num)
		{
//			for (int i=0;i<=lim-1;i++)
//			{
//				cout<<b[i]<<" ";
//			}
//			cout<<endl;
			ans++;
		}
		return;
	}
	if (step==n+1)
	{
		return;
	}
	b[ge]=step;
	dfs(step+1,lim,ge+1,num+a[step],a[step]);
	b[ge]=0;
	dfs(step+1,lim,ge,num,mx);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=3;i<=n;i++)
	{
		dfs(1,i,0,0,0);
	}
	cout<<ans;
	return 0;
}
