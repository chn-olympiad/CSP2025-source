#include <bits/stdc++.h>
using namespace std;
inline int read(){
	char c;
	do{
		c=getchar();
	}while(c<'0'||'9'<c);
	int sum=0;
	do{
		sum=10*sum+c-'0';
		c=getchar();
	}while('0'<=c&&c<='9');
	return sum;
}
typedef long long ll;
const int N=11000,M=1100000,L=11;
const ll INF=1e18;
int n,m,K;
struct eg{
	int u,v,w;
}a[M+L*N];
int c[L];
int f[N],siz[N];
inline void init(){
	for(int i=1;i<=n+K;i++)
		f[i]=i,siz[i]=1;
}
inline int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
inline bool merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)
		return 0;
	if(siz[x]>siz[y])
		swap(x,y);
	f[x]=y;
	siz[y]+=siz[x];
	return 1;
}
vector <int> e[1<<L][2];
bool vis[1<<L];
ll ans=INF;
void calc(int s){
	ll res=0;
	init();
	for(int k=1;k<=K;k++)
		if(s&(1<<(k-1)))
			res+=c[k];
	for(int i:e[s][0])
		if(merge(a[i].u,a[i].v)){
			e[s][1].push_back(i);
			res+=a[i].w;
		}
	ans=min(ans,res);
}
void mg(int s,int t,int k){
	for(int i=0,j=0;i<(int)e[s][1].size()||j<n;){
		if(j==n||(i<(int)e[s][1].size()&&a[e[s][1][i]].w<a[m+(k-1)*n+j+1].w))
			e[t][0].push_back(e[s][1][i++]);
		else
			e[t][0].push_back(m+(k-1)*n+(++j));
	}
}
void dfs(int s){
	vis[s]=1;
	calc(s);
	for(int k=1;k<=K;k++){
		int t=s|(1<<(k-1));
		if(vis[t])
			continue;
		mg(s,t,k);
		dfs(t);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),K=read();
	for(int i=1;i<=m;i++)
		a[i].u=read(),a[i].v=read(),a[i].w=read();
	sort(a+1,a+m+1,[](const eg x,const eg y){
		return x.w<y.w;
	});
	for(int k=1;k<=K;k++){
		c[k]=read();
		for(int i=1;i<=n;i++)
			a[m+(k-1)*n+i].u=n+k,a[m+(k-1)*n+i].v=i,a[m+(k-1)*n+i].w=read();
		sort(a+m+(k-1)*n+1,a+m+k*n+1,[](const eg x,const eg y){
			return x.w<y.w;
		});
	}
	for(int i=1;i<=m;i++)
		e[0][0].push_back(i);
	dfs(0);
	printf("%lld\n",ans);
	return 0;
}
