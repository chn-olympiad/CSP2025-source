#include<bits/stdc++.h>
#define up(i,l,r) for(int i=l,END##i=r;i<=END##i;i++)
#define dn(i,l,r) for(int i=l,END##i=r;i>=END##i;i--)
#define ve vector<int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second
#define great greater<int>
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
using namespace std;
const int N=1e4+17,M=1e6+7;
const i64 INF=1e18;
int fa[N],sz[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
struct node{	
	i64 u,v,w;
}a[M+N*10],aa[M+N*10];
bool f[13];
int b[13][N];
int n,m,k,q;
i64 ans=INF;
void dfs(int x){
	if(x==k+1){
		up(i,1,n+k) fa[i]=i,sz[i]=1; 
		i64 s=0;
		up(i,1,k) if(f[i]) s+=b[i][0];
		q=m;
		int o=n;
		up(i,1,m) a[i]=aa[i];
		up(i,1,k) if(f[i]){
			o++;
			up(j,1,n) a[++q].u=o,a[q].v=j,a[q].w=b[i][j];
		}
		sort(a+1,a+q+1,[](node x,node y){
			return x.w<y.w;
		});
		up(i,1,q){
			int x=a[i].u,y=a[i].v;
			x=find(x),y=find(y);
			if(x==y) continue;
			s+=a[i].w,fa[x]=y,sz[y]+=sz[x];
			if(sz[y]==o) break;
		}
		ans=min(ans,s);
		return;
	}
	up(i,0,1) f[x]=i,dfs(x+1),f[x]=0;
}
namespace sol{
	i64 read(){
		i64 x=0,f=0;
		char c=getchar();
		while(c<'0'||c>'9') f|=c=='-',c=getchar();
		while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
		return f?-x:x;
	}
	void write(i64 x){
		if(x<0) x=-x,putchar('-');
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	void work(){
		up(i,1,n) fa[i]=i,sz[i]=1;
		q=m;
		up(i,1,k){
			int id=0;
			up(j,1,n) if(!b[i][j]){id=j;break;}
			up(j,1,n) if(j!=id) a[++q].u=id,a[q].v=j,a[q].w=b[i][j];
		}
		i64 s=0;
		sort(a+1,a+q+1,[](node x,node y){
			return x.w<y.w;
		});
		up(i,1,q){
			int x=a[i].u,y=a[i].v;
			x=find(x),y=find(y);
			if(x==y) continue;
			s+=a[i].w,fa[x]=y,sz[y]+=sz[x];
			if(sz[y]==n) break;
		}
		write(s);
	}
	void Dianaqwq(){
		bool check=1;
		n=read(),m=read(),k=read();
		up(i,1,m){
			a[i].u=read(),a[i].v=read(),a[i].w=read();
			aa[i]=a[i];
		}
		up(i,1,k) up(j,0,n) b[i][j]=read();
		up(i,1,k){
			if(b[i][0]){check=0;break;}
			bool qwq=0;
			up(j,1,n) if(!b[i][j]){qwq=1;break;}
			if(!qwq){check=0;break;}
		}
		if(check)return work(),void();
		dfs(1);
		write(ans);
	}
}
using namespace sol;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	Dianaqwq();
	return 0;
}
