#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,v,w;
}e[1000021];
node g[102012];
int tot=0;
int fa[100211];
int siz[100201];
int a[11][102011];
int find(int x){
	while(x!=fa[x])x=fa[x]=fa[fa[x]];
	return x;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
vector<node> E;
int c[101001];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++){
		cin >>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+m+1,cmp);
	int sum=0,cnt=0;
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			if(siz[e[i].u]<siz[e[i].v])swap(e[i].u,e[i].v);
			siz[e[i].u]+=siz[e[i].v];
			cnt++;
			fa[find(e[i].v)]=find(e[i].u);
			g[++tot]=e[i];
			if(cnt==n-1)break;
		}
	}
	for(int i=1;i<=k;i++){
		cin >>c[i];
		for(int j=1;j<=n;j++){
			cin >>a[i][j];
		}
	}
	int l=(1<<k)-1;
	int res=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<=l;i++){
		E=vector<node>();
		for(int j=1;j<=n+11;j++)fa[j]=j,siz[j]=1;
		for(int j=1;j<n;j++)E.push_back(g[j]);
		int ans=0,cnt=0;
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				cnt--;
				ans+=c[j+1];
				for(int t=1;t<=n;t++){
					E.push_back(node{t,n+j+1,a[j+1][t]});
				}
			}
		}
		if(ans>res)continue;
		sort(E.begin(),E.end(),cmp);
		for(node t:E){
			if(find(t.u)!=find(t.v)){
				cnt++;
				if(siz[t.u]<siz[t.v])swap(t.u,t.v);
				siz[t.u]+=siz[t.v];
				fa[find(t.v)]=find(t.u);
				ans+=t.w;
				if(ans>res)break;
				if(cnt==n-1)break;
			}
		}
		res=min(ans,res);
	}
	cout <<res;
}
