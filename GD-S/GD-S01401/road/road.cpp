#include <bits/stdc++.h>
using namespace std;

void read(int &n){
	n=0; char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		n=(n<<3)+(n<<1)+(ch^48);
		ch=getchar();
	}
	return ;
}

struct edge{int to,w;};
struct node{
	int f,to,w;
	friend bool operator <(node i,node j){return i.w>j.w;}
};
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
int n,m,k;
int tag[20],c[20],a[13][10005];
vector<edge> E[10005];
int fa[10005];
node tr[10005],tr2[10005];
int minn[20],d[20]; //minn:离关键点最近，d:该距离 

int myfind(int u){
	if(fa[u]==u) return u;
	return fa[u]=myfind(fa[u]);
}

void merge(int u,int v){
	u=myfind(u),v=myfind(v);
	fa[u]=v;
}
bool tag2[10005]={0};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	priority_queue<node> Q;
	for(int i = 1,u,v,w; i<=m; i++){
		read(u),read(v),read(w);
		E[u].push_back((edge){v,w});
		E[v].push_back((edge){u,w});
	}
	for(int i = 1; i<=k; i++){
		read(c[i]); tag[i]=false;
		for(int j = 1; j<=n; j++) read(a[i][j]);
	}
	for(int i = 1; i<=n; i++) for(auto v:E[i]) Q.push((node){i,v.to,v.w}),fa[i]=i;
	int cnt=0; long long ans=0;
	while(Q.size()){
		auto q=Q.top(); Q.pop();
		int u=q.f,v=q.to,w=q.w;
		if(myfind(u)==myfind(v)) continue;
		merge(u,v);
		tr[++cnt]=(node){u,v,w},ans+=w;
	}
	if(k==0) {
		cout<<ans<<'\n';
		return 0;
	}
	long long output=ans;
	long long ans2=ans;
	for(int i=1; i<=k; i++){
		for(int j=1; j<=n; j++){
			if(!a[i][j]) d[i]=j;
		}
	}
	for(int i=1; i<=k; i++){
		for(int e=1; e<=cnt; e++){
			int u=tr[e].f,v=tr[e].to,w=tr[e].w;
			if(u==d[i]||v==d[i]){
				if(u==d[i]){
					if(a[i][v]<w){
						ans2+=(a[i][v]-w);
						tr[e].w=a[i][v];
					}//sekai shi ne
				}else{
					if(a[i][u]<w){
						ans2+=(a[i][u]-w);
						tr[e].w=a[i][u];
					}
				}
				continue;
			}
			if(a[i][u]>a[i][v]){
				if(w<=a[i][v]) continue;
				ans2+=(a[i][v]-tr[e].w);
				tr[e].w=a[i][v];
			}else{
				if(w<=a[i][u]) continue;
				ans2+=(a[i][u]-tr[e].w);
				tr[e].w=a[i][u];
			}
		}
	}
	output=min(output,ans2);
	cout<<output;
	return 0;
}
