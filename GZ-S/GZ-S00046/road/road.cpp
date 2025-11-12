//GZ-S00046 刘啸行 贵阳市新世界学校
#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,u,w;
}b[100005];
bool cmp(node A,node B){
	return A.w<B.w;
} 
int ind = 0,c[15],fa[10015],cc[15]={0},cw[15]={0};
bool vis[10015]={0};
void add(int u,int v,int w){
	b[ind++].w = w;
	b[ind].v = v;
	b[ind].u = u;
}
int find(int i){
	if(fa[i]==i)return i;
	else return fa[i]=find(fa[i]);
}
void comb(int i,int j){
	int fi = find(i),fj = find(j);
	fa[fi] = fj;
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i = 1;i<=k;i++){
		int tmpa;
		cin >> c[i];
		for(int j = 1;j<=n;j++){
			cin >> tmpa;
			add(i+10000,j,tmpa);
			add(j,i+10000,tmpa);
		}
	}
	for(int i = 1;i<=n+k;i++)fa[i]=i;
	sort(b+1,b+1+(m+k*n)*2,cmp);
	long long ans = 0;
	int cnt = 0,i = 0;
	while(1){
		i++;
		int v = b[i].v,u = b[i].u,w = b[i].w;
		if(find(u)==find(v))continue;
		cnt++;
		if(cnt>=n+k)break;
		ans+=w;
		comb(u,v);
		if(!vis[u])vis[u]=1;
		if(!vis[v])vis[v]=1;
		if(u>10000){
			cc[u-10000]++;
			if(cc[u-10000]==1)cw[u-10000]=w;
		}
		if(v>10000){
			cc[v-10000]++;
			if(cc[v-10000]==1)cw[v-10000]=w;
		}
	}
	for(int i = 1;i<=k;i++){
		if(cc[i]==1) ans-=cw[i];
		else ans+=c[i];
	}cout << ans;
	return 0;
}

