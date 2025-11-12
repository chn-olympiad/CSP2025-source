#include<bits/stdc++.h>
using namespace std;
int a[5005],s[5005],ans=0,n;
const int M=998244353;
struct node
{
	int sum,step,t;
};
void bfs(int d,int max)
{
	queue<node> q;
	node x;
	x.sum=0;
	x.step=0;
	x.t=0;
	q.push(x);
	while(!q.empty())
	{
		node now=q.front();
		int u=now.sum,v=now.step,w=now.t;
		bool f=0;
		if(v==d-1&&w==0) f=1;
		if(v==d&&w>=2)
		{
			if(u>max) ans=(ans+1)%M;
		}
		if(v+1<=d&&f==0)
		{
			q.push({u+a[v+1],v+1,w+1});
			q.push({u,v+1,w});
		}
		q.pop();
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		if(s[i-1]>a[i]) bfs(i-1,a[i]);
	}
	cout<<ans%M;
	return 0;
}
