#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int maxn = 1e4+10;
struct node{
	int u,v;
	int val;
};
vector<node> p[maxn];
int a[15][maxn];
struct nk{
	int pass,id,fa;
	long long money;
};
queue<nk> q;
long long ans=1e18+10;
bool vis[maxn][maxn];
void bfs()
{
    nk s; s.id=1;
	s.pass=1; s.money=0;
	s.fa=0;
    q.push(s);
    while(!q.empty())
    {
    	nk tmp=q.front();q.pop();
    	if(tmp.pass==n)
    	{
    		ans=min(ans,tmp.money);
    		continue;
		}
    	for(int i=0;i<p[tmp.id].size();i++)
    	{
    		if(!vis[p[tmp.id][i].u][p[tmp.id][i].v]&&p[tmp.id][i].v!=tmp.fa)
    		{
    			vis[p[tmp.id][i].u][p[tmp.id][i].v]=1;
    			nk h; 
				h.id=p[tmp.id][i].v; h.money=p[tmp.id][i].val+tmp.money;
			
				h.pass=tmp.pass+1; h.fa=tmp.id;
					cout<<h.id<<" "<<h.money<<" "<<h.pass<<endl;
				q.push(h);
			}
		}
	}
}
void solve()
{
	bfs();
	cout<<ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
    	int u,v,val;
    	node a; 
    	cin>>u>>v>>val;
    	a.u=u,a.v=v,a.val=val;
    	p[u].push_back(a);
    	node b;
    	b.u=v,b.v=u,b.val=val;
    	p[v].push_back(b);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a[i][0];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	if(k==0)
	{
		solve();
	}
	else{
		solve2();
	}
	return 0;
 } 
