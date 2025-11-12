#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define c(i,j) (m+(i-1)*k+j)
inline int read(){
	register int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if (ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
typedef pair<int,int> pii;
struct node{
	int u,v,w;
	inline bool operator < (const node& u)const{
		return w<u.w;
	}
}a[N];
//vector<node> G[N];
int n,m,k,cnt,e,used;
long long ans;
int c[N];
int fa[N];
int vis[N];
inline int getf(int u){
	return (u==fa[u]?u:fa[u]=getf(fa[u]));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		a[++e]={min(u,v),max(u,v),w};
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			int w=read();
			a[++e]={j,i+n,w+c[i]};
		}
	}
	sort(a+1,a+e+1);
//	for(int i=1;i<=e;i++)cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<endl;
	for(int i=1;i<=m+e;i++){
		int u=a[i].u,v=a[i].v;
		if (v>n){
			if(!vis[v-n])used++;
			vis[v-n]++;
//			if (!vis[v-n])ans+=c[v-n],vis[v-n]=true,used++;
		}
		int fu=getf(u),fv=getf(v);
		if (fu==fv)continue;
		fa[fu]=fv;ans+=a[i].w;
		cnt++;
		if (cnt==n+used-1)break;
//		cout<<i<<" "<<ans<<endl;
	}
	for(int i=1;i<=k;i++)if (vis[i]>1)ans-=(c[i]*(vis[i]-1));
	cout<<ans<<'\n';
	return 0;
}
