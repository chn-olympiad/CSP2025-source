#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=1e6+5;
int n,m,k,f[N],cnt,ans,vis[N],a[N],tot,s[N],s1[N];
struct node{
	int u,v,w; 
}e[M]; 
int find(int x) {
	return (x==f[x]?x:f[x]=find(f[x]));
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n>>m>>k;
	for (int i=1;i<=n;i++) {
		f[i]=i;
	}
//	memset(w,-1,size(w));
	for (int i=1;i<=m;i++) {
		cin >>e[i].v>>e[i].u>>e[i].w;
//		w[e[i].u][e[i].v]=w[e[i].v][e[i].u]=e[i].w;
	}
	sort(e+1,e+m+1,[](node a,node b){return a.w<b.w;});
	for (int i=1;i<=m&&cnt!=n-1;i++) {
		int u=find(e[i].u),V=find(e[i].v);
		if (u==V) continue;
		f[u]=V;
		ans+=e[i].w;
	}
	for (int i=1;i<=k;i++) {
		int x,flay=0;
		cnt=0;
		cin >>x;
		flay|=x!=0;
		for (int j=1;j<=n;j++) {
			cin >>a[j];
			f[i]=i;
			flay|=a[j]!=0;
		}
		if (!flay) {
			cout <<0<<"\n";
			return 0;
		}
		
	}
	cout <<ans;
	return 0;
}
