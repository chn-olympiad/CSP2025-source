#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e4+20;
const int M=4e6+20;
inline int read(){
	int f=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=(k<<1)+(k<<3)+(c^48);
		c=getchar();
	}
	return f*k;
}
int n,m,q;
struct mouse_king{
	int u,v,w;
}edge[M];
int c[N];
int a[11][N];
int fa[N];
int ans=0;
inline int find(int x){
	if(fa[x]==x) return fa[x];
	else return fa[x]=find(fa[x]);
}
inline void hb(int x,int y){
	x=find(x),y=find(y);
	fa[y]=x;
}
inline bool cmp(mouse_king x,mouse_king y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		edge[i].u=read();
		edge[i].v=read();
		edge[i].w=read();
	}
	for(int i=1;i<=q;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	if(n<=1001){
		int cnt=m;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int w=1e18;
				for(int k=1;k<=q;k++){
					w=min(w,a[k][i]+a[k][j]+c[k]);
				}
				edge[++cnt].u=i;
				edge[cnt].v=j;
				edge[cnt].w=w;
			}
		}
		sort(edge+1,edge+cnt+1,cmp);
		int x,y;
		for(int i=1;i<=cnt;i++){
			x=edge[i].u;
			y=edge[i].v;
			if(find(x)!=find(y)){
				ans+=edge[i].w;
				hb(x,y);
			}
		}
		cout<<ans<<"\n";
	}else{
		sort(edge+1,edge+n+1,cmp);
		for(int i=1;i<=n;i++){
			int x=edge[i].u;
			int y=edge[i].v;
			if(find(x)!=find(y)){
				ans+=edge[i].w;
				hb(x,y);
			}
		}
		cout<<ans<<endl;
	}
	
	
	
	return 0;
}
