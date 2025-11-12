#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v,w;
};
struct edge{
	long long wz,qz;
	bool operator<(const edge&_)const{
		return qz>_.qz;
	}
};
vector<node>g[10005];
long long n,m,k;
long long a[15][10005];
long long extra[1100];
long long l(long long num){
	long long p=0;
	while(num)
	{
		p++;
		num/=2; 
	}
	return p;
}
priority_queue<edge>q;
bool inq[10005]; 
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>m>>k;
	long long i,j;
	for(i=1;i<=m;i++)
	{
		long long u,v,w;
		cin>>u>>v>>w;
		g[u].push_back(node{v,w});
		g[v].push_back(node{u,w});
	} 
	for(i=1;i<=k;i++)
	{
		for(j=0;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	long long ans=1e17;
	for(i=0;i<(1<<k);i++)
	{
		if(i!=0)
		{
			extra[i]=extra[i-(i&(-i))]+a[l(i&(-i))][0]+a[l(i&(-i))][l(i&(-i))];
		}
		while(!q.empty())
		{
			q.pop();
		}
		memset(inq,false,sizeof(inq));
		q.push(edge{1,0});
		long long now=extra[i];
		while(!q.empty())
		{
			long long np=q.top().wz;
			if(inq[np])
			{
				q.pop();
				continue;
			}
			now+=q.top().qz;
			q.pop();
			inq[np]=true;
			for(j=0;j<g[np].size();j++)
			{
				if(inq[g[np][j].v])
				{
					continue;
				}
				q.push(edge{g[np][j].v,g[np][j].w});
			}
			if(np<=k&&(i&(1<<np-1)))
			{
				for(j=1;j<=n;j++)
				{
					if(inq[j])
					{
						continue;
					}
					q.push(edge{j,a[np][j]});
				}
			}
			for(j=1;j<=k;j++)
			{
				if(inq[j]||(i&(1<<j-1))==0)
				{
					continue;
				}
				q.push(edge{j,a[j][np]});
			}
		}
		ans=min(ans,now);
	}
	cout<<ans;
	
	return 0;
} 
