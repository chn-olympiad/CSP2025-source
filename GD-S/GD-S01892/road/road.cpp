#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long
const int N=1e4+5,M=1e7+5;
int n,m,k;
struct edge{
	int u,v;ll w;
}e[M];
ll ans=1e18,res;
unordered_map<int,ll> mp[11],mp1[N];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fa[N];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
bool merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return false;
	fa[fx]=fy;
	return true;
}
int tot;
ll c[N];
ll kruskar(){
	sort(e+1,e+tot+1,cmp);
	ll sum=0,cnt=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=tot;i++){
		int x=e[i].u,y=e[i].v;
		ll z=e[i].w;
		if(merge(x,y)) {
			sum+=z;
			if(++cnt==n) break;
		}
	}return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		if(mp1[e[i].u].count(e[i].v)&&e[i].w<mp1[e[i].u][e[i].v]){
			mp1[e[i].u][e[i].v]=mp1[e[i].v][e[i].u]=e[i].w;
		}
		else mp1[e[i].u][e[i].v]=mp1[e[i].v][e[i].u]=e[i].w;
	}m=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(mp1[i].count(j)) e[++m].u=i,e[m].v=j,e[m].w=mp1[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
		}
	}
	if(!k){
		ans=kruskar();
	}else{
		for(int i=1;i<(1<<k);i++){//枚举城市化改造的城镇 
			res=0;tot=m;
			for(int j=0;j<k;j++){
				if((i>>j)&1){
					res+=c[j+1];
					for(int x=1;x<=n;x++){
						for(int y=1;y<=n;y++){
							e[++tot].u=x,e[tot].v=y,e[tot].w=mp[j+1][x]+mp[j+1][y];
							if(tot>M-5) break;
						}if(tot>M-5) break;
					}
				}
			}tot=min(tot,M-5);
			ans=min(ans,kruskar()+res);
		}
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
废了，分数还没去年高 
*/
