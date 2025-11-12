#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 10005+10,MAXM = 1000005;
struct node{
	int u,v;
	long long w;
	bool coun,create;
};
vector<node> edge;
int f[MAXN];
long long c[MAXN];
bool bec[MAXN];
int find(int x)
{
	if(f[x] == x)
		return x;
	return f[x] = find(f[x]);
}
void insert(int x,int y)
{
	int fx = find(x),fy = find(y);
	if(fx != fy)
		f[fy] = fx;
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 1;i <= n;i++)
		f[i] = i;
	for(int i = 1;i <= m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		edge.push_back({a,b,c,false});
	}
	bool flag = true;
	for(int i = 1;i <= k;i++)
	{
		scanf("%d",&c[i]);
		if(c[i] != 0)
			flag = false;
		for(int j = 1;j <= n;j++)
		{
			int a;
			scanf("%d",&a);
			if(a != 0)
				flag = false;
			edge.push_back({n+i,j,a+c[i],true,true});
			edge.push_back({n+i,j,a,true,false});
		}
	}
	if(flag)//预计A性质满分，32pts 
	{
		cout<<0;
		return 0;
	}
	sort(edge.begin(),edge.end(),cmp);//最小生成树，预计 16~24pts 
	long long ans = 0;
	for(int i = 0;i < edge.size();i++)
	{
		if(find(edge[i].u) != find(edge[i].v))
		{	
			if(edge[i].coun == false)
			{
				//cout<<edge[i].u<<' '<<edge[i].v<<' '<<edge[i].w<<endl;
				insert(edge[i].u,edge[i].v);
				ans+=edge[i].w;
			}
			else
			{
				if(edge[i].create == false)//当前边是不作为改造乡村的边 
				{
					if(bec[edge[i].u])//如果已经改造过
					{
						insert(edge[i].u,edge[i].v);
						ans+=edge[i].w;	
					} 
					
				}
				else
				{
					if(!bec[edge[i].u])//没有被改造过，要作为改造乡村的边 
					{
						bec[edge[i].u] = true;
						insert(edge[i].u,edge[i].v);
						ans+=edge[i].w;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
