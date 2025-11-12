#include<bits/stdc++.h>
#define ll unsigned long long
#define il inline
#define gc getchar
#define pc putchar
#define int unsigned
using namespace std;
int n,m,k;
char ch;int res;
il int read(){
	res=0,ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch&15),ch=gc();
	return res;
}
void print_(ll x){
	if(!x) return;
	print_(x/10);
	pc(x%10+'0');
}
void print(ll x){
	if(!x) pc('0');
	else print_(x);
	pc('\n');
}
const int sz1=10000;
const int sz2=1000000;
struct edge{
	int u,v,w;
}e[sz2*2+5];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int cn,c[sz1+5],a,p;
int cnt[(1<<10)+5];
int fa[(1<<10)+5][sz1+5];
ll ans[(1<<10)+5];
il int find(int k,int x){
	if(fa[k][x]!=x) fa[k][x]=find(k,fa[k][x]);
	return fa[k][x];
}
int mx[(1<<10)+5];
il bool mrg(int k,int x,int y,int w){
	if(cnt[k]==mx[k]) return 0;
	x=find(k,x),y=find(k,y);
	if(x==y) return 0;
	fa[k][y]=x,++cnt[k],ans[k]+=w;
	return 1;
}
const ll inf=1e18;
ll mnans=inf;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) e[i].u=read(),e[i].v=read(),e[i].w=read();
	cn=m;
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a=read();
			++cn;
			e[cn].u=n+i;
			e[cn].v=j;
			e[cn].w=a;
		}
	}
	for(int i=0;i<(1<<k);i++){
		mx[i]=n-1;
		for(int j=0;j<k;j++) if(i&(1<<j)) ans[i]+=c[j+1],++mx[i]; 
		for(int j=1;j<=n+k;j++) fa[i][j]=j;
	}
	sort(e+1,e+cn+1,cmp);
	for(int i=1;i<=cn;i++){
		if(e[i].u<=n){
			if(mrg(0,e[i].u,e[i].v,e[i].w))
				for(int j=1;j<(1<<k);j++)
					mrg(j,e[i].u,e[i].v,e[i].w);
		}
		else{
			p=(1<<(e[i].u-n-1));
			if(mrg(p,e[i].u,e[i].v,e[i].w))
				for(int j=0;j<(1<<k);j++)
					if(j&p) mrg(j,e[i].u,e[i].v,e[i].w);
		}
	}
	for(int i=0;i<(1<<k);i++) mnans=min(mnans,ans[i]);
	print(mnans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
