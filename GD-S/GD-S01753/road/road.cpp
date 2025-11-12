#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
const int N=2e6+7;
int n,m,k,idx,d,u,v,w,c[N],f[N],a[17][10007];
struct node{
	int w,d,u,v;
}p[N];
ll ans=1e18+7,cnt;
bool cmp(node x,node y){
	return x.w<y.w;
}
inline int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
inline void func(int x){
	cnt=0;
	for(re int i=0;i<k;i++) if(x>>i&1) cnt+=c[i+1];
	for(re int i=1;i<=n+k;i++) f[i]=i;
	for(re int i=1;i<=idx;i++){
		w=p[i].w,u=p[i].u,v=p[i].v;
		d=p[i].d;
		if(d&&!((x>>d-1)&1)) continue;
		u=find(u),v=find(v);
		if(u==v) continue;
		f[u]=v,cnt+=w;
	}
	ans=min(ans,cnt);
}
inline int read(){
	char f=0;
	int res=0;
	while(1){
		f=getchar();
		if(f>='0'&&f<='9') res=res*10+f-48;
		else break;
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read(),idx=m;
	for(re int i=1;i<=m;i++){
		u=read(),v=read(),w=read();
		p[i].w=w,p[i].d=0,p[i].u=u,p[i].v=v;
	}
	for(re int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) w=read(),++idx,p[idx].w=w,p[idx].d=i,p[idx].u=i+n,p[idx].v=j;
	}
	sort(p+1,p+idx+1,cmp);
	for(re int i=0;i<(1<<k);i++) func(i);
	cout<<ans;
	return 0;
} 
