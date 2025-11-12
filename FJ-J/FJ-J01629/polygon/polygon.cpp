#include<bits/stdc++.h>
using namespace std;
int n,a[50005],v[50005],ans;
struct node
{
	int h,maxn,k;
};
queue <node> q;
void bfs()
{
	q.push({0,0,1});
	while(!q.empty())
	{
		node x=q.front();q.pop();
		if(x.h>x.maxn*2) 
		{
			ans++;
		}
		for(int i=x.k;i<=n;i++)
		{
			q.push({x.h+a[i],max(x.maxn,a[i]),i+1});
		}
	}
	return;
}
//void dfs(int h,int maxn,int k)
//{
//	if(h>2*maxn) 
//	{
//		ans++;
//	}
//	for(int i=k;i<=n;i++)
//	{
//		if(v[i]!=1)
//		{
//			v[i]=1;
//			dfs(h+a[i],max(maxn,a[i]),i);
//			v[i]=0;
//		}
//	}
//	return;
//}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	//dfs(0,0,0);
	bfs();
	cout<<ans;
	return 0;
}
