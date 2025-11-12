#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,m,k;
struct ee{
	int uu,to,next,cost;
}e[MAXN*20];
int fa[MAXN*2];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int cnt,head[MAXN];
void add(int u,int v,int w){
	e[++cnt].uu=u;
	e[cnt].to=v;
	e[cnt].cost=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int o[25],f[MAXN],w[25];
int cmp(ee x,ee y){
	if(x.cost==y.cost)return x.cost;
	return x.cost<y.cost;
}
int chack(ee ed){
	if(find(ed.to)==find(ed.uu))return 0;
	if(ed.to>n){
		if(!o[ed.to-n])return 0;
	}
	if(ed.uu>n){
		if(!o[ed.uu-n])return 0;
	}
	return 1;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		int kp[MAXN];
		cin>>w[i];
		for(int j=1;j<=n;j++){
			cin>>kp[j];
			add(i+n,j,kp[j]);
		}
	}
	sort(e+1,e+1+cnt,cmp);
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int p=0;p<=1<<k-1;p++){
		int t=0,d=n;
		memset(o,0,sizeof(o));
			for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1;i<=k;i++){
			if((1<<i)&p){
				o[i]=1;
				f[p]+=w[i];
				d++;
			}
		}
		int i=0;
		while(t<=d-2){
			i++;
			if(chack(e[i])){
				t++;
				fa[e[i].to]=find(fa[e[i].uu]);
				f[p]+=e[i].cost;
			}		
		}
	}
	int minn=0x3f3f3f;
	for(int i=0;i<=1<<k-1;i++){
		minn=min(minn,f[i]);
	}
	cout<<minn;
	return 0;
}
