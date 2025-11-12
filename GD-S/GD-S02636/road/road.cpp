#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+10;
int n,m,q;
int cnt;
struct edge{
	int u,v,w;
}e[maxn<<1];
int cmp(edge a,edge b){
	return a.w<b.w;
}
int f[maxn];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int kus(){
	sort(e+1,e+cnt+1,cmp);
	for(int i = 1;i<=n;i++){
		f[i]=i;
	}
	int lin = 0,ans = 0;
	for(int i = 1;i<=cnt;i++){
		int u = find(e[i].u),v = find(e[i].v),w = e[i].w;
		if(u==v){
			continue;
		}
		f[u]=v;
		ans+=w;lin++;
		if(lin==n-1)break;
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>q;
	for(int i = 1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[++cnt]={u,v,w};
	}
	int Mi = kus();
	
		cout<<Mi;
		return 0;
	
	
	
} 


