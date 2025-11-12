#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define N 10005
#define M 1000005
#define K 12
#define ll long long
using namespace std;
int read(){
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	int x=0;
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x;
}
void write(ll x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int n,m,k;
ll ans,res;
struct edge{
	int u,v,w;
	bool operator < (const edge a)const{
		return w<a.w;
	}
}a[M],d[N],f[N*11];
int c[K],b[K][N];
int fa[N+K];
int find(int i){return fa[i]?fa[i]=find(fa[i]):i;}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t=clock();
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) a[i].u=read(),a[i].v=read(),a[i].w=read();
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) b[i][j]=read();
	}
	sort(a+1,a+1+m);
	int u,v,w,cnt=0,cntf;
	for(int i=1;i<=m;i++){
		u=a[i].u,v=a[i].v,w=a[i].w;
		u=find(u),v=find(v);
		if(u==v) continue;
		fa[u]=v;
		d[++cnt]=a[i];
		ans+=w;
		if(cnt==n-1) break;
	}
	for(int i=(1<<k);i>=1;i--){
		cnt=n;
		for(int j=0;j<k;j++) if(i&(1<<j)) cnt++; 
		for(int j=1;j<n;j++) f[j]=d[j]; cntf=n-1;
		for(int j=1;j<=n+k;j++) fa[j]=0;
		res=0;
		for(int j=1;j<=k;j++){
			if(i&(1<<j-1)){
				res+=c[j];
				for(int t=1;t<=n;t++) f[++cntf]={j+n,t,b[j][t]};			
			}
		}
		if(res>=ans) continue;
		sort(f+1,f+1+cntf);
		for(int j=1;j<=cntf;j++){
			u=f[j].u,v=f[j].v,w=f[j].w;
			u=find(u),v=find(v);
			if(u==v) continue;
			fa[u]=v;
			res+=w;
			if(res>=ans) break;
			cnt--;
			if(cnt==1) break;
		}
		ans=min(ans,res);
	}
	write(ans);
	return 0;
}
