#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int s=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		s=(s<<3)+(s<<1)+(c^48);
		c=getchar();
	}
	return s*f;
}
inline void write(int x){
	if(x<0){
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+48);
}
int n,m,k,u,v,a,head[10015],sum,tot,dis[10015],vis[10015],tmp[10015],ord[15],delta[15],cs;
struct ad{
	int cos,a[10005];
};
ad edge[15];
struct node{
	int fa,to,nxt,num;
};
node e[4000005];
void add(int a,int b,int c){
	e[++sum].fa=a;
	e[sum].to=b;
	e[sum].num=c;
	e[sum].nxt=head[a];
	head[a]=sum;
}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int prim(){
	memset(dis,0x7f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	int s=0;
	dis[1]=0;
	q.push({0,1});
	while(!q.empty()){
		int tmp=q.top().second;
		q.pop();
		if(vis[tmp]){
			continue;
		}
		s+=dis[tmp];
		vis[tmp]=1;
		for(int i=head[tmp];i;i=e[i].nxt){
			if(dis[e[i].to]>e[i].num){
				dis[e[i].to]=e[i].num;
				q.push({e[i].num,e[i].to});
			}
		}
	}
	return s;
}
bool cmp(int a,int b){
	return delta[a]>delta[b];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++){
		u=read();
		v=read();
		a=read();
		add(u,v,a);
		add(v,u,a);
	}
	for(int i=1;i<=k;i++){
		edge[i].cos=read();
		for(int j=1;j<=n;j++){
			edge[i].a[j]=read();
		}
	}
	if(!k){
		write(prim());
		return 0;
	}
	for(int i=1;i<=k;i++){
		ord[i]=i;
	}
	int s1=prim();
	for(int i=1;i<=k;i++){
		tot=sum;
		for(int j=1;j<=n+k;j++){
			tmp[j]=head[j];
		}
		for(int j=1;j<=n;j++){
			add(n+k,j,edge[i].a[j]);
			add(j,n+k,edge[i].a[j]);
		}
		delta[i]=s1-prim()-edge[i].cos;
		sum=tot;
		for(int j=1;j<=n+k;j++){
			head[j]=tmp[j];
		}
	}
	sort(ord+1,ord+k+1,cmp);
	for(int kk=1;kk<=k+1;kk++){
		int s0=prim();
		if(kk==k+1){
			write(s0+cs);
			return 0;
		}
		for(int i=1;i<=n;i++){
			add(n+ord[kk],i,edge[ord[kk]].a[i]);
			add(i,n+ord[kk],edge[ord[kk]].a[i]);
		}
		if(s0<prim()+edge[ord[kk]].cos){
			write(s0+cs);
			return 0;
		}
		cs+=edge[ord[kk]].cos;
	}
	return 0;
}
