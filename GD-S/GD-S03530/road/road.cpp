#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6;
struct node{
	int u,v,w;
}edge[N];
int c[N],d[N],f[N],bj[N];
int bcj(int x){
	if(f[x]==x) return x;
	f[x]=bcj(f[x]);
	return f[x];
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,x,y,z;
	ll minn=1e18,sf=0;
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
		edge[i].u=read(),edge[i].v=read(),edge[i].w=read();
	for(int i=1;i<=k;i++){
		c[i]=read();
		sf+=c[i];
		for(int j=1;j<=n;j++){
			edge[++m].u=n+i,edge[m].v=j;
			edge[m].w=read();
		}
	}
	sort(edge+1,edge+m+1,cmp);
	for(int id=pow(2,k)-1;id>=0;id--){
		int s=id,s1=0,h=0;
		ll ans=0;
		for(int i=1;i<=k;i++) d[i]=0;
		while(s) d[++s1]=s%2,s/=2,ans+=c[s1]*d[s1];
		for(int i=1;i<=n;i++) f[i]=i,bj[i]=1;
		for(int i=n+1;i<=n+k;i++) f[i]=i,bj[i]=d[i-n];
		for(int i=1;i<=m;i++){
			x=edge[i].u,y=edge[i].v,z=edge[i].w;
			if(bj[x]==0||bj[y]==0||bcj(x)==bcj(y)) continue;
			f[bcj(x)]=bcj(y),ans+=z,h++;
			if(h==m-1) break;
		}
		if(sf==0){
			printf("%lld",ans);
			return 0;
		}
		minn=min(minn,ans);
	}
	printf("%lld",minn);
	return 0;
} 
