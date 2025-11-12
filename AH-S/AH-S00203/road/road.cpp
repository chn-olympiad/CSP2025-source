#include<bits/stdc++.h>
using namespace std;
struct node{
	long long u,v,w;
}edge[50005010];
bool vis[10010][10010];
long long n,m,k,c,a[15][10010],f[10010],z[10010][10010],ans,cnt,fx,fy;
bool cmp(node x,node y){
	return x.w < y.w;
}long long find(long long x){
	if(f[x] == x)	return x;
	return f[x] = find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	cnt = n;
	for(int i = 1;i <= n;i++)
		f[i] = i;
	for(int i = 1;i <= m;i++){	
		cin>>edge[i].u>>edge[i].v>>edge[i].w;	
		vis[edge[i].u][edge[i].v] = 1;
		z[edge[i].u][edge[i].v]	= i;
		vis[edge[i].v][edge[i].u] = 1;
		z[edge[i].v][edge[i].u]	= i;
	}
	for(int i = 1;i <= k;i++){
		cin>>c;
		for(int j = 1;j <= n;j++)
			cin>>a[i][j];		
	}
	for(int i = 1;i <= n;i++)
		for(int j = i + 1;j <= n;j++)
			for(int l = 1;l <= k;l++)
				if(vis[i][j])	edge[z[i][j]].w = min(edge[z[i][j]].w,a[l][i] + a[l][j]);
				else
				{
					edge[++m].w = a[l][i] + a[l][j];
					edge[m].u = i;
					edge[m].v = j;
					vis[i][j] = 1;
					vis[j][i] = 1;
					z[i][j] = m;
					z[j][i] = m;
				}
	sort(edge + 1,edge + 1 + m,cmp);
	for(int i = 1;i <= m&&cnt > 1;i++){
		fx = find(edge[i].u);
		fy = find(edge[i].v);
		if(fx != fy){
			f[fx] = fy;
			cnt--;
			ans += edge[i].w;
		}
	}cout<<ans<<endl;
	return 0;
}
