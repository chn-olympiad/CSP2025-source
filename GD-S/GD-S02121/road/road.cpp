#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+2;
int n,m,k;
struct edge{
	int u,v,w;	
}e[N*100];
int fa[N];

void init(void){
	for(int i=1;i<=n;i++) fa[i]=i;
	cout<<fa[1];
}
int find(int x){
	if(x==fa[x]) return x;
	return find(fa[x]);
}
int u(int x){
	fa[x]=find(fa[x]);
}
bool cmp(edge aaa,edge bbb){
	return aaa.w<bbb.w;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	int idx=1,pdx=1;//edge_index
	for(int i=1;i<=m;i++){
		int ppp,lll,mmm;
		cin>>ppp>>lll>>mmm;
		e[i].u=ppp,e[i].v=lll,e[i].w=mmm;
	}
	int minx=1e18;
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		minx=min(c,minx);
		for(int i=1;i<=n;i++) cin>>c;
	}
	int cnt=0,ans=0;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(cnt==n-1) break;
		if(find(u)==find(v)) continue;
		cnt++;
		if(u<v) swap(u,v);
		fa[v]=min(fa[u],fa[v]);
		fa[u]=min(fa[u],fa[v]);
		ans+=w;
		
	}
	cout<<min(minx,ans);
	return 0;
}
//Only A

















/*
Hopefully I will have a better future,whether studying or OIing. 
One of a spiderman.
Luogu,Codeforces,Atcoder,Genshin:Wzmois 
Welcome to add me.
rp++
Love Mois Forever.
*/
