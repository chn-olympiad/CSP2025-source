#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+10;
int c[15][N],point,side,w,n,m,k,cnt,fa[N],ans=1e18;
struct Edge{
	int u,v,w;
}E[N];
struct edge{
	int u,v,w;
}e[N];

bool cmp1(Edge a,Edge b){
	return a.w<b.w;
}

bool cmp2(edge a,edge b){
	return a.w<b.w;
}

int get(int x){
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}

void merge(int x,int y){
	fa[get(x)]=get(y);
}

void kruscal1(){
	int res=0;
	for(int i=1;i<=m;i++){
		int u=E[i].u,v=E[i].v,w=E[i].w;
		if(get(u)==get(v)) continue;
		merge(u,v);
		res+=w;
		e[++cnt].u=u,e[cnt].v=v,e[cnt].w=w;
	}
	ans=res;
}



signed main(){
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<N;i++) fa[i]=i;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>E[i].u>>E[i].v>>E[i].w;
	sort(E+1,E+1+m,cmp1);
	kruscal1();
	bool flag=false;
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		if(c!=0) flag=1;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			if(x!=0) flag=1;
		}
	}
	if(flag==0&&k!=0) cout<<0;
	else cout<<ans;
	return 0;
}
