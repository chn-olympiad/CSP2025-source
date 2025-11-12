#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;
const int N=1e4+5;
int hd[M*2],tot,a[N],f[N],ok[N+N];
int find(int x){
	if (f[x]==x)return x;
	return f[x]=find(f[x]);
}
void join(int x,int y){
	f[find(x)]=find(y);
}
struct edge{
	int st,to,nxt,w;
}e[M*2];
void add(int u,int v,int w){
	e[++tot].to=v;
	e[tot].st=u;
	e[tot].w=w;
	e[tot].nxt=hd[u];
	hd[u]=tot;
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	for (int i=1;i<=m;++i){
		int u,v,w;cin>>u>>v>>w;
		add(u,v,w),add(v,u,w);
	}
	for (int i=1;i<=n;++i)f[i]=i;
	sort(e+1,e+tot+1,cmp);
	int cnt=0,cnt2=0;
	for (int i=1;i<=tot;++i){
		int s=e[i].st,t=e[i].to;
		if (find(s)!=find(t)){
			join(s,t),cnt++;
			cnt2+=e[i].w;
		}
		if (cnt==n-1)break;
	}
	cout<<cnt2;
}
