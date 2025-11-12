#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005],cnt,vis[1000005],maxn;
struct Node{
	int left,right,sum,cnt;
};
queue<Node> Q;
void BFS()
{
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)
		{
			continue;
		}
		Q.push({i,i+1,a[i],0});
	}
	while(!Q.empty())
	{
		Node t=Q.front();
		Q.pop();
		for(int i=t.left+1;i<=n;i++)
		{
			if(vis[i]==1||vis[t.left]==1)
			{
				break;
			}
			t.right=i;
			t.sum^=a[i];
			if(t.sum==k)
			{
				Q.push({t.right+1,t.right+1,t.sum,t.cnt+1});
			} 
		}
		maxn=max(Q.front().cnt+cnt,maxn);
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//A^B=C B^C=A A^C=B
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			vis[i]=1;
			cnt++;
		}
	}
	BFS();
	cout<<maxn<<endl;
	return 0;
}
