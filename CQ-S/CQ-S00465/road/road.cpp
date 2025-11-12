#include<bits/stdc++.h>
const int QWQ=1e4+15;
using namespace std;
using LL=long long;
inline int read(){
	int x=0,f=1; char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar())
		if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
struct node{ int u,v,w; };
vector<node> E[1<<10],G[10];
int n,m,k,Fa[QWQ],c[11]; LL ans;
int get(int k){
	return Fa[k]!=k ? Fa[k]=get(Fa[k]):k;
}
inline LL MST(vector<node> &e){
	vector<node> vc; LL sum=0;
	for (int i=1;i<=n+k;i++) Fa[i]=i;
	sort(e.begin(),e.end(),[&](node x,node y){
		return x.w<y.w;
	});
	for (auto [u,v,w]:e){
		int a=get(u),b=get(v);
		if (a==b) continue;
		Fa[b]=a,sum+=w;
		vc.push_back({u,v,w});
	}
	swap(vc,e),vc.shrink_to_fit();
	return sum;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		E[0].push_back({x,y,z});
	}
	for (int i=0;i<k;i++){
		c[i]=read();
		for (int j=1;j<=n;j++)
			G[i].push_back({i+1+n,j,read()});
	}
	ans=MST(E[0]);
	for (int s=1;s<(1<<k);s++){
		int i=0; for (;;i++) if (s>>i&1) break;
		E[s]=E[s-(1<<i)]; LL tmp=0;
		for (int j=0;j<k;j++) if (s>>j&1) tmp+=c[j];
		for (auto x:G[i]) E[s].push_back(x);
		ans=min(ans,tmp+MST(E[s]));
	}
	printf("%lld",ans);
	return 0;
} 
