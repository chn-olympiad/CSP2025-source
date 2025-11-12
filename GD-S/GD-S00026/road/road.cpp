#include<bits/stdc++.h>
using namespace std;
const int maxn=1100005;
typedef long long ll;
struct node{
	int u,v,w,ww;
}e[maxn];
bool cmp(node a,node b){return a.w+a.ww<b.w+b.ww;}
int fa[maxn<<1],s[maxn<<1];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
bool vis[maxn<<1];
struct nodee{int u,v,w;};
vector<nodee> vec;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=(n<<1);++i) fa[i]=i;
	for(int i=1;i<=m;++i){
		int x,y,z;scanf("%d %d %d",&x,&y,&z);
		e[i]={x,y,z,0};
	}
	int tot=m;
	for(int i=1;i<=k;++i){
		int c;scanf("%d",&c);
		for(int j=1;j<=n;++j){
			int x;scanf("%d",&x);
			e[++tot]={i+n,j,x,c};
		}
	}
	sort(e+1,e+tot+1,cmp);
	ll sum=0;
	for(int i=1;i<=tot;++i){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			if(e[i].ww&&!vis[e[i].u]) vec.push_back({e[i].u,e[i].v,e[i].ww+e[i].w}),vis[e[i].u]=1;
			else vec.push_back({e[i].u,e[i].v,e[i].w});
		}
	}
	for(auto i:vec) ++s[i.u];
	for(auto i:vec){
		if(s[i.u]==1&&i.u>n) continue;
		sum+=i.w;
	}
	printf("%lld",sum);
}
/*
zmx lsy
千万不要删这行，别问我为什么，删了会寄
*/
