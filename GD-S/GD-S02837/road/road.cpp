#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace FastIO{
	template<class T>
	T read(T&x){
		x=0;bool f=false;char ch=getchar();
		while(!isdigit(ch)) f|=!(ch^'-'),ch=getchar();
		while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch&0xF),ch=getchar();
		x=(f?-x:x);return x;
	}template<class T>
	void write(T x,char ch=' '){
		if(x<0) putchar('-'),x=-x;
		char tmp[41];int cnt=0;
		while(x>9) tmp[cnt++]=x%10+'0',x/=10;tmp[cnt++]=x+'0';
		while(cnt) putchar(tmp[--cnt]);putchar(ch);
	}
};
using namespace FastIO;
const int N=1e4+10,M=1e6+10,K=11;
struct Edge{int u,v,w;}E[M];
struct disjoint_union_set{
	int fa[N+20];
	void init(int n){for(int i=1;i<=n;i++) fa[i]=i;}
	int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
	inline bool merge(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return false;
		fa[x]=y;return true;
	}
}DSU;
int a[K][N],c[K],n,m,k,cnt;
vector<Edge>e[1<<K],cur;
ll ans;
inline bool cmp(Edge x,Edge y){return x.w<y.w;}
void solve(int pre,int now,int p){
	cur=e[pre];
	ll res=0;int furry=0;
	for(int i=0;i<k;i++){
		if(now&(1<<i)) res+=c[i],furry++;
	}
	DSU.init(n+k);
	for(int i=1;i<=n;i++) cur.emplace_back((Edge){n+p+1,i,a[p][i]});
	sort(cur.begin(),cur.end(),cmp);
	int siz=cur.size(),tot=0;
	for(int i=0;i<siz;i++){
		int u=cur[i].u,v=cur[i].v,w=cur[i].w;
		if(DSU.merge(u,v)) res+=w,tot++,e[now].emplace_back(cur[i]);
		if(tot==n+furry-1) break;
	}
	ans=min(ans,res);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++) read(E[i].u),read(E[i].v),read(E[i].w);
	for(int i=0;i<k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++) read(a[i][j]);
	}
	DSU.init(n);
	sort(E+1,E+m+1,cmp);
	int tot=0;
	for(int i=1;i<=m;i++){
		int u=E[i].u,v=E[i].v,w=E[i].w;
		if(DSU.merge(u,v)) e[0].emplace_back(E[i]),ans+=w,tot++;
		if(tot==n-1) break;
	}
	for(int i=1;i<(1<<k);i++){
		for(int j=0;j<k;j++){
			if(i&(1<<j)){solve(i^(1<<j),i,j);break;}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
