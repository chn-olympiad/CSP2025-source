#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int M = 1e4+4;
ll n,m,k;
struct G{
	ll u,v,w;
}p[1000006];
struct T{
	ll to,w,nxt;
}e[3000006];
ll ans,an[20],head[M+100],cnty,vi[20],fa[M];
ll u,v,w;
ll c[20],a[12][10004];
ll vis[M+10],cnt;

struct node{
	ll d,x,fa;
	friend bool operator < (const node &a,const node &b){
		return a.d>b.d;
	}
};
priority_queue<node> q;
ll dis,h,f;

bool cmp(G x,G y){
	return x.w<y.w;
}
long long find(int u){
	while(u!=fa[u]) u=fa[u]=fa[fa[u]];
	return u;
}
void prim(){
	cnt++;
	q.push({0,1,0});
	while(cnt<=n){
		dis=q.top().d;h=q.top().x,f=q.top().fa;
		q.pop();
		if(vis[h]) continue;
		vis[h]=1;
		if(h<=n) cnt++;
		if(f<=n&&h<=n) {ans+=dis;}
		if(f>n) {vi[f-n]=1;an[f-n]+=dis;}
		if(h>n){an[h-n]+=dis;}
		for(int i=head[h];i;i=e[i].nxt){
			int y=e[i].to;
			q.push({e[i].w,y,h});
		}
	}
}

void add(ll u,ll v,ll w){
	e[++cnty] = T{v,w,head[u]};
	head[u]=cnty;
}
inline long long rd(){
	ll x=0,f=1;
	char c; c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c-'0');c=getchar();}
	return x*f;
}
inline void pu(long long x){
	if(x<0) {putchar('-');x=-x;}
	if(x>9) pu(x/10);
	putchar((x%10+'0'));}
	
long long kl(){	
	for(int i=0;i<=n;i++){
		fa[i]=i;
	}
	sort(p+1,p+m+1,cmp);
	for(int i=1;i<=m;i++){
		u=p[i].u,v=p[i].v;
		u=find(u),v=find(v);
		if(u!=v){
			ans+=p[i].w;
			fa[u]=v;
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd(),m=rd(),k=rd();
	
	for(int i=1;i<=m;i++){
		u=rd(),v=rd(),w=rd();
		p[i].u=u,p[i].v=v;p[i].w=w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			if(j==1) {c[i]=rd();}
			else {a[i][j-1]=rd(); add(j-1,i+n,c[i]+a[i][j-1]);add(i+n,j-1,a[i][j-1]);}
		}
	}
	if(k==0) {
		ans=0;
		ans=kl();
		printf("%lld\n",ans);
		return 0;
	}
	prim();
	//cout<<ans<<endl;
	for(int i=1;i<=k;i++)
	{
		if(vi[i]) ans+=an[i];
	}
	printf("%lld\n",ans);
	return 0;
}
