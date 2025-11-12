#include<bits/stdc++.h>
#define int long long
namespace FastIO{
	template<typename T>inline void read(T &x){
		x=0;int f=1;char c=getchar();
		for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
		for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);x*=f;
	}
	template<typename T,typename...Args>
	inline void read(T &x,Args&...args){
		read(x);
		read(args...);
	}
	template<typename T>void print(T x){
		if(x<0)x=-x,putchar('-');
		if(x>9)print(x/10);
		putchar((x%10)^48);
	}
}
using namespace FastIO;
using namespace std;
const int N=1e4+15;
int n,m,K,fa[N],cnt,mst,c,dis,sum[N],mn[N];
struct node{
	int u,v,w;
}; 
vector<node>a;
bool cmp(node a,node b){
	return a.w<b.w;
}
int Find(int x){
	if(x==fa[x])return x;
	return fa[x]=Find(fa[x]);
}
void join(int x,int y){
	int fx=Find(x);
	int fy=Find(y);
	if(fx!=fy){
		fa[fy]=fx;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n,m,K);
	for(int i=1;i<=m;i++){
		int u,v,w;
		read(u,v,w);
		a.emplace_back(node{u,v,w});
	}
	for(int i=1;i<=n+K;i++)fa[i]=i;
	memset(mn,0x3f,sizeof mn);
	for(int i=1;i<=K;i++){
		read(c);
		for(int j=1;j<=n;j++){
			read(dis);
			a.emplace_back(node{j,n+i,dis});
			m++;
			mn[n+i]=min(mn[n+i],dis);
		} 
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<m;i++){
		sum[a[i].u]++;
		sum[a[i].v]++;
		int fx=Find(a[i].u);
		int fy=Find(a[i].v);
		if(fx!=fy){
			cnt++;
			mst+=a[i].w;
			join(fx,fy);
			if(cnt==n+K-1)break;
		}
	}
	for(int i=1;i<=K;i++){
		if(sum[n+i]==1)mst-=mn[n+i];
	}
	print(mst);
	return 0;
}