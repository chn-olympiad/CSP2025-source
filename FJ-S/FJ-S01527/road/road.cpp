#include<bits/stdc++.h>
#define gc() getchar()
#define int long long
#define r(x) (x)=read()
using namespace std;
const int N=1e6+5;
inline int read(){
	int x=0,f=1;char c=gc();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=gc();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=gc();}
	return x*f;
}
inline void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
struct node{
	int u,v,w;
};
inline bool cmp(node a,node b){
	return a.w<b.w;
}
int n,m,k,f[N],dis[N];
vector<node>vi;
vector<int>svi[N];
int find(int x){
	while(x!=f[x])x=f[x]=f[f[x]];
	return x;
}
inline void solve(){
	r(n),r(m),r(k);
	if(k!=0){
		putchar(0);
		return;
	}
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		r(u),r(v),r(w);
		vi.push_back({u,v,w});
		vi.push_back({v,u,w});
	}
	for(int i=1;i<=k;i++){
		int c,aji;
		r(c);
		for(int i=1;i<=n;i++){
			r(aji);
			svi[c].push_back(aji);
		}
	}
	sort(vi.begin(),vi.end(),cmp);
	int cnt=0,ans=0;
	for(int i=1;i<=2*m;i++){
		int fx=find(vi[i].u),fy=find(vi[i].v);
		if(fx!=fy){
			f[fy]=fx;
			ans+=vi[i].w;
			if(++cnt==n-1){
				write(ans);
				return;
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t=1;
	//r(t);
	while(t--)solve();
	return 0;
}

