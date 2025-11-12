//怎么说呢，感觉不像是贪心又像是贪心
//真的好难啊，还是打个暴力吧
//特殊性质就是说白送你城市化
#define ll long long
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+500;
//vector <node> g[N];
int anc[N];
struct path1{
	int u;
	int v;
	ll w;
}e[3000050];//没办法了
bool cmp(path1 x,path1 y){
	return x.w<y.w;
}
int f(int x){
	if(anc[x]==x)return x;
	anc[x]=f(anc[x]);
	return anc[x];
}
bool comb1(int x,int y){
	int fx=f(x),fy=f(y);
	if(fx!=fy){
		anc[fx]=fy;
		return 1;
	}
	return 0;
}
int cnt;
int n;
ll kruskal(){
	ll ans=0;
	sort(e+1,e+1+cnt,cmp);
	int b=0;
	for(int i=1;i<=cnt;i++){
		if(comb1(e[i].u,e[i].v)){
			if(e[i].u<=n and e[i].v<=n)b++;
			ans+=e[i].w;
			//b++;
			//if(b==n-1)break;
		}
	}
	return ans;
}
ll val[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=k+k+n;i++)anc[i]=i;
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		//g[u].push_back({v,w});
		//g[v].push_back({u,w});
		cnt++;
		e[cnt].u=u;
		e[cnt].v=v;
		e[cnt].w=w;
	}
	ll ans1=kruskal();
	for(int i=1;i<=k;i++){
		cin>>val[i];
		for(int j=1;j<=n;j++){
			cnt++;
			e[cnt].u=n+i;
			e[cnt].v=j;
			cin>>e[cnt].w;
		}
	}
	for(int i=1;i<=n+k+k;i++)anc[i]=i;
	ll ans2=kruskal();
	cout<<min(ans2,ans1);
	return 0;
}
