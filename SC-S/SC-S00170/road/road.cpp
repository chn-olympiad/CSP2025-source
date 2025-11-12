#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
vector<pair<int,int>> a[N];
int n,m,k,cost[15],vis[N]; 
int F(int z)
{
	int g=n+k-z;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	vis[1]=1;
	for(pair<int,int> i:a[1])
	{
		if(vis[i.second]) continue;
		q.push(i);
	}
	int ans=0,cnt=1;
	while(cnt!=g)
	{
		pair<int,int> tp=q.top(); q.pop();
		int tpf=tp.first,tps=tp.second;
		if(vis[tps]) continue;
		vis[tps]=1,cnt++,ans+=tpf;
		for(pair<int,int> x:a[tps])
		{
			if(vis[x.second]) continue;
			q.push(x);
		}
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n >>m >>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,val; cin >>u >>v >>val;
		pair<int,int> p1,p2;
		p1.first=val,p1.second=v;
		p2.first=val,p2.second=u;
		a[u].push_back(p1);
		a[v].push_back(p2);
	}
	for(int i=1;i<=k;i++) 
	{
		int flg=1;
		cin >>cost[i];
		if(cost[i]!=0) flg=0;
		for(int j=1;j<=n;j++)
		{
			int val; cin >>val;
			if(val!=0) flg=0;
			pair<int,int> p1,p2;
			p1.first=val,p1.second=n+i;
			p2.first=val,p2.second=j;
			a[j].push_back(p1);
			a[n+i].push_back(p2);
		}
		if(flg==1) return cout <<"0",0;
	}
	int ans=4e18;
	for(int i=0;i<(1<<k);i++)//1 -> do not use
	{
		int sum=0,num=0;
		for(int j=0;j<k;j++) 
		{
			if((i>>j)&1) vis[n+j+1]=1,num++;
			else sum+=cost[j+1];
		}
		ans=min(F(num)+sum,ans);
		for(int j=1;j<=n+k;j++) vis[j]=0;
	}
	cout <<ans;
	return 0;
} 