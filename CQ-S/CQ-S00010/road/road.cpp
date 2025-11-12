#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+20;
const int inf=0x3f3f3f3f;
inline int read(){
	char ch=getchar();
	int f=1,s=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=(s<<1)+(s<<3)+ch-'0';
		ch=getchar();
	}
	return f*s;
} 
int n,m,k,fa[N];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
struct edge{
	int u,v,w;
}e[N*105];
bool cmp(edge p,edge q){
	return p.w<q.w;
}
int cnt,ans;
vector <edge> G[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		e[++cnt]=edge{u,v,w};
	}
	bool f=0;
	for(int i=1;i<=k;i++){
		int c=read();
		if(c)f=1;
		for(int j=1;j<=n;j++){
			int w=read();
			if(w)f=1;
			e[++cnt]=edge{n+1,j,w+c};
		}
	}
	if(!f){
		cout<<0<<"\n";
		return 0;
	}
	for(int i=1;i<=n+k;i++)fa[i]=i;
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			fa[fu]=fv;
			ans+=w;
		}
	}
	printf("%lld\n",ans);
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
