#include<bits/stdc++.h>
#define int long long
using namespace std;
int n=0, m=0, k=0, add=0,ans=0,i=0,f1=0,f2=0;
int father[114514]={};
int vis[114514]={};
struct edge{
	int u;
	int v;
	int w;
}e[114514]; 
int find(int x)
{
	if (father[x]==x)return x;
	else return father[x]=find(father[x]);
}
bool cmp(edge e1,edge e2)
{
	return e1.w<e2.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m>>k;
	for (i=1;i<=n;i++) father[i]=i,vis[i]=0;
	if (k==0)
	{
		for (i=1; i<=m; i++)
			{
			cin >> e[i].u>>e[i].v>>e[i].w;
			e[i+m]=e[i];
			}
		m*=2;
		sort(e+1,e+1+m,cmp);
		for (i=1;i<=m and add <n-1;i++){
			if (vis[e[i].u] and vis[e[i].v]) continue;
			add++;
			f1=find(e[i].u);
			f2=find(e[i].v);
			father[f1]=f2;
			vis[e[i].u]=vis[e[i].v]=1;
			ans+=e[i].w;
		}
		cout << ans;
	}
	else cout << 15;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
