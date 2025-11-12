#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std; bool MEM;
using ll=long long; using ld=long double;
using pii=pair<int,int>; using pll=pair<ll,ll>;
void rd(int &x) {
	char c; while (c=getchar(),!('0'<=c&&c<='9')); x=c-'0';
	while (c=getchar(),'0'<=c&&c<='9') x=x*10+c-'0';
}
const int I=1e9,N=1e4+17,M=1e6+17,K=10;
const ll J=1e18;
// watch out size
int n,m,nm,k,c[K],a[K][N],sz[1<<K]; ll sm[1<<K],ans=J;
struct edg { int x,y,z; } b[M],e[1<<K][N];
int f[N];
void ini() { iota(f+1,f+n+k+1,1); }
int fnd(int x) { return f[x]==x?x:f[x]=fnd(f[x]); }
void mian() {
	rd(n),rd(m),rd(k);
	for (int i=1,x,y,z;i<=m;i++) rd(x),rd(y),rd(z),b[i]={x,y,z};
	sort(b+1,b+m+1,[&](edg x,edg y){return x.z<y.z;});
	ini(); int mm=m; m=0; ll sum=0;
	for (int i=1;i<=mm;i++) {
		int fx=fnd(b[i].x),fy=fnd(b[i].y);
		if (fx!=fy) b[++m]=b[i],f[fx]=fy,sum+=b[i].z;
	}
	ans=sum;
//	cerr<<ans<<"\n";
//	printf("%lld\n",ans);
	for (int o=0;o<k;o++) { rd(c[o]); for (int i=1;i<=n;i++) rd(a[o][i]); }
	for (int s=1;s<1<<k;s++) {
		if (__builtin_popcount(s)==1) {
			int p=__lg(s);
			for (int i=1;i<=n;i++) e[s][i]={n+p+1,i,a[p][i]};
			sort(e[s]+1,e[s]+n+1,[&](edg x,edg y){return x.z<y.z;}),sm[s]=c[p],sz[s]=n;
		}
		else {
			ini();
			int x=s&-s,y=s^s&-s; sm[s]=sm[x]+sm[y];
			for (int l=1,r=1,c=0;l<=sz[x]&&r<=sz[y];) {
				edg w;
				if (l<=sz[x]&&(r>sz[y]||e[x][l].z<e[y][r].z)) w=e[x][l++];
				else w=e[y][r++];
				int fx=fnd(w.x),fy=fnd(w.y);
				if (fx!=fy) e[s][++sz[s]]=w,f[fx]=fy;
			}
		}
		ini(); ll res=sm[s]; int lim=n+__builtin_popcount(s);
		for (int l=1,r=1,c=0;l<n&&r<=sz[s]&&c<lim;) {
			edg w;
			if (l<n&&(r>sz[s]||b[l].z<e[s][r].z)) w=b[l++];
			else w=e[s][r++];
			int fx=fnd(w.x),fy=fnd(w.y);
			if (fx!=fy) f[fx]=fy,res+=w.z,c++;
//			printf(" %d %d %d\n",w.x,w.y,w.z);
		}
//		printf("%d %lld\n",s,res);
		ans=min(ans,res);
	}
	cout<<ans;
}
bool ORY; int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	while (1)
//	int t; for (scanf("%d",&t);t--;)
	mian();
	cerr<<"\n"<<abs(&MEM-&ORY)/1048576<<"MB";
	return 0;
}
/*
连通图，每条边有边权 
有 n 个特殊点 
可以选择若干个特殊点，有点权
然后可以解锁这个特殊点到别的城市的点权
并不能直接枚举哪些特殊点选然后做。
但是考虑一个神秘操作。我们先对初始的 m 条边做最小生成树
边数就可以降到 n-1。然后再去枚举选哪些特殊点 
这样应该就是 O(2^k n) 的，顶多再带一个和最小生成树无关的 k 
应该是能过的，注意常数。 

感觉不是很简单啊。 
*/
