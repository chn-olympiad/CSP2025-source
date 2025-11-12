#include<bits/stdc++.h>
#define ll int
using namespace std;
const int N=2000010;
const long long INF=0x3f3f3f3f3f3f3f3f;
ll read(){
	ll x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*y;
}
void write(long long x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
struct edge{
	ll x,y,z;
}a[N];

ll n,m,K;
ll fa[N],siz[N];
ll w[N];
ll tmp,num;
long long ans;

inline ll fnd(ll x){return fa[x]==x?x:fa[x]=fnd(fa[x]);}
inline void merge(ll x,ll y){
	x=fnd(x),y=fnd(y);
	if(x==y) return ;
	if(siz[x]>siz[y]) swap(x,y);
	fa[x]=y,siz[y]+=siz[x];
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),K=read();
	for(int i=1;i<=m;i++) a[i].x=read(),a[i].y=read(),a[i].z=read();
	sort(a+1,a+m+1,[&](edge x,edge y)->bool{return x.z<y.z;});
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++){
		if(fnd(a[i].x)==fnd(a[i].y)) continue;
		merge(a[i].x,a[i].y);
		a[++tmp]=a[i];
	}
	m=tmp;
	for(int i=1;i<=K;i++){
		w[i]=read();
		for(int j=1;j<=n;j++) a[++m].x=n+i,a[m].y=j,a[m].z=read();
	}
	sort(a+1,a+m+1,[&](edge x,edge y)->bool{return x.z<y.z;});
	ans=INF;
	for(int i=0;i<(1<<K);i++){
		for(int j=1;j<=n+K;j++) fa[j]=j,siz[j]=1;
		long long res=0;num=n-1;
		for(int j=0;j<K;j++) if(i>>j&1) res+=w[j+1],num++; 
		if(res>=ans) continue;
		for(int j=1;j<=m;j++){
			if(a[j].x<=n||i>>(a[j].x-n-1)&1){
				if(fnd(a[j].x)==fnd(a[j].y)) continue;
				merge(a[j].x,a[j].y);
				res+=a[j].z;num--;
				if(res>=ans) break;
				if(!num) break;
			}
		}
		ans=min(ans,res);
	}
	write(ans),putchar('\n');
	return 0;
}
