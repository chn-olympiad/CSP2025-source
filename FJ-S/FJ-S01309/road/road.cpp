#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
struct node{
	int l,r,val,ch=0;
}a[N];
int n,m,k,f[N];
int vv[15],ex[15][N];
bool open[15];
inline int find(int x){ return f[x]==x?x:f[x]=find(f[x]);}
inline void merge(int x,int y){ f[find(x)]=f[find(y)];}
inline bool cmp(node a,node b){ return a.val<b.val;}
struct tree{
	int to,next,c;
	bool pass;
}e[N];
int pos=0,head[N];
inline void add(int u,int v,int w){
	pos+=1;
	e[pos].next=head[u];
	e[pos].to=v;
	e[pos].c=w;
	head[u]=pos;
	return;
}
int ban;
bool vis[N];
inline void dfs(int u,int fa){
	vis[u]=1;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		//cout << "搜了" << u << " " << v << "\n";
		if(fa==0&&e[i].to==ban) e[i].pass=1;
		if(v==fa||e[i].pass) continue;
		dfs(v,u);
	}
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++) cin >> a[i].l >> a[i].r >> a[i].val;
	for(int i=1;i<=k;i++){
		cin >> vv[i];
		for(int j=1;j<=n;j++) cin >> ex[i][j];
	}
	sort(a+1,a+m+1,cmp);
	int ans=0,tmp=0;
	for(int i=1;i<=m;i++){
		if(find(a[i].l)!=find(a[i].r)){
			merge(a[i].l,a[i].r);
			ans+=a[i].val;
			a[i].ch=1;
			add(a[i].l,a[i].r,a[i].val);
			add(a[i].r,a[i].l,a[i].val);
			tmp+=1,a[tmp].l=a[i].l,a[tmp].r=a[i].r,a[tmp].val=a[i].val;
		}
	}
	if(k==0){
		cout << ans << "\n";
		return 0;
	}
	//for(int i=1;i<=tmp;i++) cout << e[i].l << " "<< e[i].r << " " << e[i].val << "\n";
	// 问题：当我拆掉最大的那一条边时，我怎么知道我的这个点能和对面的产生联系？ 
	// 暴力即可
	// 问题：我怎么拆边完再建边呢？ 
	// 给边打上标记即可！ 
	for(int i=tmp;i>=1;i--){
		if(a[i].ch!=1) continue;
		ban=a[i].l;
		dfs(a[i].r,0);
		for(int j=1;j<=n;j++) vis[j]=0;
		ban=a[i].r;
		dfs(a[i].l,0);
		//cout << "dfs" << a[i].l << " " << a[i].r << "!\n";
		//for(int j=1;j<=n;j++) cout << vis[j] << " ";
		//cout << "\n";
		int point=0,len=1e18;
		for(int j=1;j<=k;j++){
			int dis=1e18;
			for(int v=1;v<=n;v++){
				if(!vis[v]) {
					dis=min(dis,ex[j][a[i].l]+ex[j][v]+(open[j]==1?0:vv[j]));
					if(dis<a[i].val&&dis<len){
						len=dis;
						point=v;
					}
				}
			}
		}
		open[point]=1;
		if(len<a[i].val){
			add(a[i].l,point,len);
			add(point,a[i].l,len);
			ans=ans-a[i].val+len;
			//cout << "加边" << a[i].l << "<->" << point << "\n";
		}
		//cout << point << " " << len << "\n";
		
		//break;
	}
	cout << ans << "\n";
	//cerr << "Times:" << 1.0*clock()/CLOCKS_PER_SEC << " ms\n";
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
*/
