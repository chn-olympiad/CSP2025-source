#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int buf[1<<10];
inline void print(int x,char ch=' '){
	if(x<0) putchar('-'),x=-x;
	int tot=0;
	do{
		buf[++tot]=x%10;
		x/=10;
	}while(x);
	for(int i=tot;i;i--)
		putchar(buf[i]+'0');
	putchar(ch);
}
const int MAXN=2e4+5,inf=1e18;
int n,m,k;

struct node{
	int u,v,w;
	node(int a=0,int b=0,int c=0){
		u=a;
		v=b;
		w=c;
	}
	bool friend operator<(const node &a,const node &b){
		return a.w<b.w;
	}
}e[MAXN*100];
int tot;

node a[11][MAXN];
int v[11];

int fa[MAXN],siz[MAXN];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return ;
	if(siz[x]<siz[y])
		swap(x,y);
	siz[x]+=siz[y];
	fa[y]=x;
}

int lg[MAXN];
int query(int mask){
	int ans=0;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<=k;i++){
		fa[n+i]=n+i;
		siz[n+i]=0;
		if(mask>>(i-1)&1)
			ans+=v[i];
	}

	int id[11];
	for(int i=0;i<=k;i++) id[i]=1;
	while(siz[find(1)]<n){
		node edge=node(0,0,inf);
		int mnid=0;
		if(id[0]<=tot){
			edge=e[id[0]];
			mnid=0;
		}
		for(int j=mask;j>0;j^=lowbit(j)){
			int i=lg[lowbit(j)]+1;
			if(id[i]>n) continue;
			if(a[i][id[i]].w<edge.w){
				edge=a[i][id[i]];
				mnid=i;
			}
		}

		id[mnid]++;
		if(find(edge.u)!=find(edge.v)){
			ans+=edge.w;
			merge(edge.u,edge.v);
		}
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	for(int i=1;i<=k;i++){
		v[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j].u=n+i;
			a[i][j].v=j;
			a[i][j].w=read();
		}
	}

	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++){
		fa[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		if(find(u)!=find(v)){
			e[++tot]=e[i];
			merge(u,v);
		}
	}

	int ans=inf;
	for(int i=1;i<=k;i++)
		sort(a[i]+1,a[i]+n+1);
	for(int i=0;i<k;i++) lg[1<<i]=i;
	for(int mask=0;mask<(1<<k);mask++)
		ans=min(ans,query(mask));
	print(ans);
	return 0;
}