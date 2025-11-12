#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+90+13,M=1e6+90,K=13; 
int n,m,k;
ll ans=1e18;
struct edge{
	int from,to;
	ll dis;
};
bool cmp(edge a,edge b){
	return a.dis<b.dis;
}
edge e_list[(M+N*K)*2];
int head[N],e_num;
/*
void add(int u,int v,ll w){
	e_list[++e_num].nxt=head[u];
	e_list[e_num].to=v;
	e_list[e_num].dis=w;
	head[u]=e_num; 
}
*/
int fa[N];
int find(int x){
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool used[K+N];
ll pri[K];
void kru(){
	for (int i=1;i<=n+k;i++) fa[i]=i;
	ll res=0;
	int cnt=0,use_num=n;
	for (int i=1;i<=k;i++) 
		if (used[i+n]){
			res+=pri[i];
			use_num++;
		} 
	bool f=1;
	for (int i=1;i<=e_num&&f;i++){
		int u=e_list[i].from,v=e_list[i].to;
		ll w=e_list[i].dis;
		if (used[u] && used[v]){
			if (find(u)==find(v)) continue;
			fa[find(u)]=find(v);
			res+=w;
			cnt++;
			if (res>ans) f=0;
			if(cnt==use_num-1) break;
		}
	}
	if(f) ans=min(ans,res);
	return;
}
void dfs(int dep){
	if (dep==k+1){
		kru();
		return;
	}
	used[dep+n]=1;
	dfs(dep+1);
	used[dep+n]=0;
	dfs(dep+1);
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		e_list[++e_num].from=u;
		e_list[e_num].to=v;
		e_list[e_num].dis=w;
	}
	for (int i=1;i<=n;i++) used[i]=1;
	for (int i=1;i<=k;i++){
		cin>>pri[i];
		for (int j=1;j<=n;j++){
			ll w;
			cin>>w;
			e_list[++e_num].from=n+i;
			e_list[e_num].to=j;
			e_list[e_num].dis=w;
		}
	}
	sort(e_list+1,e_list+1+e_num,cmp);
	dfs(1);
	cout<<ans;
	return 0;
}
