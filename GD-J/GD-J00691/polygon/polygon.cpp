#include<bits/stdc++.h>
using namespace std;
int a[5010],n,ans=0,vis[5010]={0},maxnum;
void dfs(int num,int ma,int len,int ii)//已选数量/最大值/长度/编号 
{
	if(num==maxnum)
	{
		if(len>2*ma)ans=(ans+1)%998244353;
		return;
	}
	for(int i=ii+1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		dfs(num+1,max(ma,a[i]),len+a[i],i);
		vis[i]=0;
	}
}
/*bool cmp(int x,int y)
{
	return x>y;
}*/
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	//sort(a+1,a+1+n,cmp);//倒序排序，最大值一定是第一个数
	for(maxnum=3;maxnum<=n;maxnum++)dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
