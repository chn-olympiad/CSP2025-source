#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct st{
	int fr=0,to=0,w=0,cho=0;
};
st road[1000005];
int bp[15][10005];
int vis[15000];
bool cmp(st a,st b)
{
	return a.w<b.w;
}
void f(int a)
{
	
}
int main()
{
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>road[i].fr>>road[i].to>>road[i].w;
	}
	for (int i=1;i<=k;i++)
	{
		for (int j=0;j<=n;j++)
		{
			cin>>bp[i][j];
		}
	}
	sort(road+1,road+m+1,cmp);
	vis[road[1].fr]=road[1].fr;
	vis[road[1].to]=road[1].fr;
	road[1].cho=1;
	int num=2;
	for (int i=2;i<=m;i++)
	{
		if(num==n)
			break;
		if(vis[road[i].fr]!=0)
		{
			if(vis[road[i].to]==0)
			{
				vis[road[i].to]=vis[road[i].fr];
				road[i].cho=1;
				num++;
			}
			else if(vis[road[i].fr]==vis[road[i].to])continue;
//			else
//			{
//				vis[road[i].to]=vis[road[i].fr];
//				f(road[i].to);
//			}
		}
		else 
		{
			if(vis[road[i].to]!=0)
			{
				vis[road[i].fr]=vis[road[i].to];
				road[i].cho=1;
				num++;
			}
			else
			{
				road[i].cho=1;
				vis[road[i].fr]=road[i].fr;
				vis[road[i].to]=road[i].fr;
				num+=2;
			}
		}
	}
	reverse(road+1,road+m+1);
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=k;j++)
		{
			int x=bp[j][0]+bp[j][road[i].fr]+bp[j][road[i].to];
			if(x<road[i].w)
			{
				road[i].w=x;
				cout<<"   "<<x<<"     ";
			 } 
		}
	}
	int sum=0;
	for (int i=1;i<=m;i++)
	{
		if(road[i].cho==1)
		{
			sum+=road[i].w;
		}
	}
	cout<<sum-2;
//	for (int i=1;i<=m;i++)
//	{
//		if(road[i].cho==1)
//		{
//			cout<<road[i].fr<<"->"<<road[i].to<<":"<<road[i].w<<endl;
//		}
//	}
} 
