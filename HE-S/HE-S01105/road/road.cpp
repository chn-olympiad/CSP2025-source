/*
1.当k=0时，该答案就是最小生成树的值 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5,M=1e6+5;
struct edge{
	int v,w;
};
struct e{
	int u,v,w;
}a[M];
int n,m,k,fa[N];
ll ans;
vector<edge>G[N];
bool b;
bool cmp(e x,e y){
	return x.w<y.w;
}
int find_fa(int x){
	if(fa[x]==x)return x;
	return fa[x]=find_fa(fa[x]);
} 
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
 	n=read(),m=read(),k=read();
 	for(int i=1,u,v,w;i<=m;++i){
 		u=read(),v=read(),w=read();
 		G[u].push_back({v,w});
 		G[v].push_back({u,w});
 		a[i].u=u,a[i].v=v,a[i].w=w;
	}
	for(int i=1;i<=n;++i)fa[i]=i;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;++i){
		int fx=find_fa(a[i].u),fy=find_fa(a[i].v);
		if(fx==fy)continue;
		fa[fx]=fy;
		ans+=a[i].w;
	}
	cout<<ans;
	return 0;
}
