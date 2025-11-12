#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define LL long long
using namespace std;
const int N=10010,M=1000010;
int n,m,k,fa[N];
LL ans;
struct edge
{
	int u,v;
	LL val;
	}e[M+10*N];
bool cmp(edge x,edge y)
{
	return x.val<y.val;
	}
int find(int x)
{
	if(fa[x]==x)
	    return x;
	return find(fa[x]);
	}
void add(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	fa[fy]=fx;
	}
void work()
{
	for(int i=1; i<=m; i++)
	{
		int fr=e[i].u,to=e[i].v,v=e[i].val;
		if(find(fr)!=find(to))
		{
			add(fr,to);
			ans+=v;
			}
		}
	}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++)
	    cin>>e[i].u>>e[i].v>>e[i].val;
	sort(e+1,e+m+1,cmp);
	for(int i=1; i<=n; i++)
	    fa[i]=i;
	work();
	cout<<ans;
	return 0;
	}
