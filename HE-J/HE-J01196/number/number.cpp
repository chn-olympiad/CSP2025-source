#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int to[110],head[110],cur[110],nxt[110],cap[110];
int tot;
void add(int u,int v,int f)
{
	to[tot]=v;
	cap[tot]=f;
	nxt[tot]=head[u];
	head[u]=tot++;
}
int s,t,maxflow;
int dis[110];
bool bfs()
{
	queue<int> q;
	memcpy(cur,head,sizeof head);
	memset(dis,0,sizeof dis);
	dis[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int j=head[u];j!=-1;j=nxt[j])
		{
			int v=to[j];
			if(!dis[v] and cap[j])
			{
				q.push(v);
				dis[v]=dis[u]+1;
				if(v==t)return 1;
			}
		}
	}
	return 0;
}
int dfs(int u,int cf)
{
	if(u==t)return cf;
	int su=0;
	for(int j=cur[u];j!=-1;j=nxt[j])
	{
		int v=to[j];
		cur[u]=j;
		if(dis[v]==dis[u]+1 and cap[j])
		{
			int k=dfs(v,min(cap[j],cf));
			if(k==0)
			{
				dis[v]=0;
				continue;
			}
			cf-=k;
			cap[j]-=k;
			cap[j^1]+=k;
			su+=k;
		}
	}
	return su;
}
void dinic()
{
	while(bfs())maxflow+=dfs(s,0x3f3f3f3f);
}
void init()
{
	memset(head,-1,sizeof head);
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	for(auto i:s1)
	{
		if(i>='0' and i<='9')s2+=i;
	}
	sort(s2.begin(),s2.end(),
		[](char x,char y)
		{
			return x>y;
		});
	cout<<s2;
}
/*
9:34
秒了前三题
发现不会第四题
前来写俳句

不闹了。

9:46
发现 D 可以推成背包。
想到三次方做法。

10:00
写出三次方做法。

10:10左右
想到正解。

10:25
打完正解。

不知道干什么。

我要上迷惑行为。
*/
