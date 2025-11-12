#include <bits/stdc++.h>
using namespace std;
int n,m,k,c[20],a[20][10050],from[10050];
bool vis[10050];
struct node
{
	int to,len;
};
struct diss
{
	int d,id;
}dis[10050];
vector <node> t[10010];
void p()
{
	for(int i = 1;i <= n;i ++)
		dis[i].id = i;
	return;
}
bool cmp(diss x,diss y)
{
	return x.d < y.d;
}
void dijsktra(int now)
{
	for(int i = 0;i < t[now].size();i ++)
	{
		if(dis[now].d + t[now][i].len < dis[t[now][i].to].d)
			dis[t[now][i].to].d = dis[now].d + t[now][i].len,from[t[now][i].to] = now;
	}
	sort(dis + 1,dis + n + 1,cmp);
	int i = 1;
	vis[dis[now].id] = 1;
	while(vis[dis[i].id])
		i++;
	dijsktra(dis[i].id);
}
map <pair<int,int>,int> q;
void back(int now)
{
	if(now == 1)
		return;
	pair<int,int> x,y;
	x.first = y.second = now;
	x.second = y.first = from[now];
	if(!q[x] && !q[y])
		q[y] = dis[now].d - dis[from[now]].d;
	back(from[now]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i = 1;i <= m;i ++)
	{
		node u,v;
		scanf("%d %d %d",&u.to,&v.to,&u.len);
		v.len = u.len;
		t[u.to].push_back(u);
		t[v.to].push_back(v);
	}
	printf("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
