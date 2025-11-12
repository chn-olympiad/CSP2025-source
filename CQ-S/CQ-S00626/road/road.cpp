#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e4+10,M=1.5e6+10;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
struct Edge{
	int u,v,w;
	bool operator <(const Edge &t)const{
		return w<t.w;
	}
}e[M];
int n,m,k;
int p[N],ans=1e18+10,c[N];
int find(int x){
	if(p[x]==x)return x;
	return p[x]=find(p[x]);
}
void solve(){
	for(int i=0;i<=n+k;i++)p[i]=i;
	sort(e+1,e+m+1);
	int res=0;
	for(int i=1;i<=m;i++){
		int pu=find(e[i].u),pv=find(e[i].v);
		if(pu==pv)continue;
		res+=e[i].w;
		p[pu]=pv;
	}
	ans=min(ans,res);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		e[i].u=read();e[i].v=read();e[i].w=read();
	}
	solve();
	for(int i=1,x;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			x=read();
			e[++m]={i+n,j,x};
		}
	}
	solve();
	cout<<ans;
	return 0;
}
