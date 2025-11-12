#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N=1e4+52,M=1e6+42;
struct edge
{
	int u,v,w;
	bool operator < (const edge &o)const{
		return w<o.w; 
	}
};
    int f[N],c[N],d[N];
vector<edge> vt;
queue<int> q;
int n,m,k;
int getfa(int x)
{
	if(f[x]==x)return x;
	return f[x]=getfa(f[x]);
}
int kr()
{
	int sum=0;
	sort(vt.begin(),vt.end());
	for(int i=0;i<vt.size();i++)
	{
		int x=getfa(vt[i].u),y=getfa(vt[i].v);
		if(x!=y)
		{
			f[y]=x;
			sum+=vt[i].w; 
		}
		
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		vt.push_back({u,v,w});
	}
	cout<<kr();
}
