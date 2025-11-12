#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#define pushs(a,b) push_back(make_pair(a,b))
using namespace std;
map<int,vector<pair<int,int> > > a;
vector<pair<int,int> > b[1001];
map<int,bool> d;
int ans=0;
int tot=0;
int n,m,k;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > c;
bool prim(int x)
{
	//cout<<x<<" ";
	if(tot==n) return 0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	for(auto i:a[x])
	{
		if(!d[i.second])
		{
			q.push(i);
		} 
	}
	while(!q.empty())
	{
		int w=q.top().first;
		int t=q.top().second;
		d[x]=1;
		ans+=w;
		tot++;
		q.pop();	
		prim(t);
	}
	return 0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int in1,in2,in3;
	for(int i=1;i<=m;i++)
	{
		cin>>in1>>in2>>in3;
		a[in1].pushs(in3,in2);
		a[in2].pushs(in3,in1);
	}
	for(int i=0;i<a[in1].size();i++)
	{
		//cout<<a[in2][i].second<<endl;
		c.push(make_pair(a[in1][i].first,a[in1][i].second));
	}
	for(int i=1;i<=k;i++)
	{
		int in0,in1,in2,in3;
		cin>>in0;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&in1);
//			b.pushs(in3,in2);
			b[i].pushs(j,in1);
		}
	}
	d[in1]=1;
	while(!c.empty())
	{
	ans+=c.top().first;
	tot++;
	c.pop();
	prim(c.top().second);
	}
	//cout<<endl;
	cout<<ans; 
	return 0;
}
