#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0; char ch; bool f=0;
	while(((ch=getchar())<'0'||ch>'9')&&ch!='-') ;
	if(ch=='-') f=1;
	else x=(ch^48);
	while((ch=getchar())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48);
	return f?-x:x;
}
const int N=1e4+55,M=1e6+5;
int n,m,k;
struct edge{
	int x,y;
	ll z;
	bool operator<(const edge &t)const{
		return z<t.z;
	}
}te[M],eg[N];
ll a[15][N],c[15];
int fa[N],sz[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int cnt;
ll ans;
int p[15][N],D,ps[15];
bool cmp(int x,int y){
	return a[D][x]<a[D][y];
}
int st[15],id[15];
void sol(int S){
//	cerr<<"sol: "<<S<<"--------------------------\n";
	int top=0;
	ll v=0;
	for(int i=1;i<=k;i++){
		if(S&(1<<i-1)){
			st[++top]=i,v=v+c[i],id[i]=top;
			ps[top]=1;
		}
	}
	ps[0]=1;
	for(int i=1;i<=n+top;i++){
		fa[i]=i; sz[i]=1;
	}
//	cerr<<v<<"\n";
	int ce=0,nd=n+top;
	while(ce<nd-1){
		ll mn=1e12; int P=0;
		for(int i=1;i<=top;i++){
			if(ps[i]<=n){
				int x=p[st[i]][ps[i]];
				if(a[st[i]][x]<mn) mn=a[st[i]][x],P=i;
			}
		}
		if(!P||(ps[0]<=cnt&&eg[ps[0]].z<mn)){
			P=0; mn=eg[ps[0]].z;
		}
		int x,y; ll z;
		if(!P) x=eg[ps[0]].x,y=eg[ps[0]].y,z=eg[ps[0]].z,ps[0]++;
		else{
			x=n+P; y=p[st[P]][ps[P]]; z=a[st[P]][y]; ps[P]++;
		}
//		cerr<<x<<" "<<y<<" "<<z<<"!!"<<mn<<"\n";
		x=get(x),y=get(y);
		if(x!=y){
			if(sz[x]>sz[y]) swap(x,y);
			fa[x]=y; sz[y]+=sz[x]; v=v+z;
			ce++;
		}
	}
//	cerr<<v<<"!!\n";
	ans=min(ans,v);
}
int main(){
//	system("fc road4.ans road.out"); return 0;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		te[i].x=read(),te[i].y=read(),te[i].z=read();
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read(),p[i][j]=j;
		D=i;
		sort(p[i]+1,p[i]+1+n,cmp);
	}
	sort(te+1,te+1+m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=te[i].x,y=te[i].y; ll z=te[i].z;
		x=get(x),y=get(y);
		if(x!=y){
			fa[x]=y; ans=ans+z; eg[++cnt]=te[i];
		}
	}
	for(int S=1;S<(1<<k);S++){
		sol(S);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
如果没有乡村,那么只有最小生成树上的边有用
所以有O(n)条
直接枚举改造的乡村集合S
边：
1.w[i]
2.a[j][i]
然后并查集
O(2^k * )
*/
