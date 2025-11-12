#include <bits/stdc++.h>
using namespace std;
struct Node{
	int u,v,w;
	bool operator<(const Node &T)const{
		return w<T.w;
	}
}edge[1000005],ok[(1<<10)+5][10105];
int n,m,k,Fa[10015],a[15][10005],c[15],id[(1<<10)+5];
long long ans=1e18;
int GetFa(int x){
	return x==Fa[x]?Fa[x]:Fa[x]=GetFa(Fa[x]);
}
int lowbit(int x){
	for (int i=0;i<k;i++) if (x&(1<<i)) return i+1;
}
long long work(int S){
	int V=(S?n+__builtin_popcount(S)-2+n:m);
	if (S){
		for (int i=1;i<=V-n;i++) edge[i]=ok[S-(S&-S)][i];
		for (int i=V-n+1;i<=V;i++) edge[i]={lowbit(S)+n,i-V+n,a[lowbit(S)][i-V+n]};
	}
	for (int i=1;i<=n+k;i++) Fa[i]=i;
	sort(edge+1,edge+V+1);
	long long res=0;
	int cnt=0,tot=0;
	for (int i=1;i<=V;i++){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		int x=GetFa(u),y=GetFa(v);
		if (x==y) continue;
		Fa[x]=y,res+=w,cnt++;
		ok[S][++tot]=edge[i];
	}
	return res;
}
int read(){
	char c=getchar();
	int x=0;
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
bool cmp(int x,int y){
	return __builtin_popcount(x)<__builtin_popcount(y);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for (int i=1;i<=m;i++) edge[i]={read(),read(),read()};
	for (int i=1;i<=k;i++){
		c[i]=read();
		for (int j=1;j<=n;j++) a[i][j]=read();
	}
	for (int S=0;S<(1<<k);S++) id[S]=S;
	sort(id,id+(1<<k),cmp);
	for (int i=0;i<(1<<k);i++){
		int S=id[i];
		long long sum=0;
		for (int j=1;j<=k;j++) if (S&(1<<(j-1))) sum+=c[j];
		ans=min(ans,sum+work(S));
	}
	printf("%lld\n",ans);
	return 0;
}
