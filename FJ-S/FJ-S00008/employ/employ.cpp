/*
18:10开D，没啥可说的上全排列吧 
这场比赛还是很难得，估分100+100+5+8
也算不留遗憾吧，CD确实能力范围之外，把我放哪我都做不了
C我觉得下位紫D我觉得上位紫/黑
唯一的遗憾就是B代码太长，太难写，导致写的太久了
或许多给我点时间，我是能切D得
但是这是如果，我B就是做了2.5h，没办法
B得话。算法不难。应该是绿，但是代码确实不好写，可能有蓝
A的话，可能对于贪心不好的人有点难度，应该是黄
许个愿，希望不挂分、七勾线、去WC、去APIO 
*/
#include<bits/stdc++.h>
using namespace std;
bool vis[100];
int c[100];
int s[100];
int n,m;
int ret;
void dfs(int nw,vector<int>res)
{
	if(nw==n)
	{
		int cnt=0,rets=0;
		for(int i=0;i<n;i++)
		{
			if(cnt>=c[res[i]-1]||s[i]==0)cnt++;
			else rets++;
		}
		if(rets>=m)
		{
			ret++;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			res.push_back(i);
			vis[i]=1;
			dfs(nw+1,res);
			res.pop_back();
			vis[i]=0;
		}
		
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%1d",&s[i]);
	}
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	vector<int>res;
	dfs(0,res);
	cout<<ret;
}
