#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e4+5,MAXM=1e6+5,MAXK=15;
int n,m,K,fa[MAXN+MAXK];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
struct edg{
	int u,v,w;
	inline friend bool operator <(edg a,edg b){
		return a.w<b.w;
	}
}e[MAXM],E[MAXN];int idx;
int c[MAXK];edg M[10*MAXN];int tot;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=K;i++){
		cin>>c[i];
		for(int j=1,x;j<=n;j++){
			cin>>x;M[++tot]=edg{i+n,j,x};
		}
	}
	sort(e+1,e+m+1);sort(M+1,M+tot+1);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		if(find(u)!=find(v)){
			fa[find(u)]=find(v);
			E[++idx]=e[i];
		}
	}
	ll ans=-1;
	for(int S=0;S<(1<<K);S++){
		ll res=0;
		for(int i=1;i<=K;i++)if(S>>(i-1)&1)res+=c[i];
		for(int i=1;i<=n+K;i++)fa[i]=i;
		int now=0;
		for(int i=1;i<=tot;i++)if(S>>(M[i].u-n-1)&1){
			while(now<=idx&&E[now].w<=M[i].w){
				int X=find(E[now].u),Y=find(E[now].v);
				if(X!=Y)fa[X]=Y,res+=E[now].w;
				now++;
			}
			int X=find(M[i].u),Y=find(M[i].v);
			if(X!=Y)fa[X]=Y,res+=M[i].w;
		}
		while(now<=idx){
			int X=find(E[now].u),Y=find(E[now].v);
			if(X!=Y)fa[X]=Y,res+=E[now].w;
			now++;
		}
		if(ans==-1)ans=res;
		else ans=min(ans,res);
	}
	cout<<ans<<"\n";
}