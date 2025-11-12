#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
int n,m,k,ans,fa[100020];
int e1[10010][20];
struct node{
	int u,v,w;
}ed[1100020];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int now){
	if(fa[now]==now)return now;
	return fa[now]=find(fa[now]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		ed[i].u=read(),ed[i].v=read(),ed[i].w=read();
	}
	for(int i=1;i<=k;i++){
		int x=read();
		for(int j=1;j<=n;j++){
			int y=read();
			ed[++m]=(node){n+i,j,x+y};
		}
	}
	n+=k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(ed+1,ed+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=find(ed[i].u),y=find(ed[i].v);
		if(x==y)continue;
		fa[x]=y;
		ans+=ed[i].w;
	}
	cout<<ans;
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


