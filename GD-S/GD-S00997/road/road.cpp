#include<bits/stdc++.h>
#define ll long long
using namespace std;
void read(int &x){
	int tmp=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		tmp=(tmp<<3)+(tmp<<1)+c-48;
		c=getchar();
	}
	x=tmp;
}
const int maxn=1e4+20,maxm=1e6+10;
int n,m,k,c[20],fa[maxn],cnt,tp,num[20],numnow;
ll ans=1e18;
struct edge{
	int u,v,w;
	bool operator < (const edge tmp) const{
		return w<tmp.w;
	}
}eg[maxm],now[maxn],stk[20][maxn],a[20][maxn];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
void dfs(int dep,ll cost){
	if(dep==k+1){
		ll tmp=0;
		for(int i=1;i<=numnow-1;i++) tmp+=now[i].w;
		ans=min(ans,tmp+cost);
		return;
	}
	dfs(dep+1,cost);
	num[++tp]=numnow;
	for(int i=1;i<=numnow-1;i++) stk[tp][i]=now[i];
	for(int i=1;i<=n+k;i++) fa[i]=i;
	int pos=0;
	cnt=0;
	for(int i=1;i<=numnow-1;i++){
		while(pos<n&&a[dep][pos+1].w<stk[tp][i].w){
			pos++;
			if(find(n+dep)!=find(a[dep][pos].v)){
				merge(n+dep,a[dep][pos].v);
				now[++cnt]=a[dep][pos];
				if(cnt==numnow-1) break;
			}
		}
		if(find(stk[tp][i].u)!=find(stk[tp][i].v)){
			merge(stk[tp][i].u,stk[tp][i].v);
			now[++cnt]=stk[tp][i];
		}
	}
	numnow++;
	dfs(dep+1,cost+c[dep]);
	numnow--;
	for(int i=1;i<=num[tp]-1;i++) now[i]=stk[tp][i];
	tp--;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		read(eg[i].u),read(eg[i].v),read(eg[i].w);
	}
	sort(eg+1,eg+m+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		if(find(eg[i].u)!=find(eg[i].v)){
			merge(eg[i].u,eg[i].v);
			now[++cnt]=eg[i];
			if(cnt==n-1) break;
		}
	}
	numnow=n;
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++) read(a[i][j].w),a[i][j].v=j,a[i][j].u=n+i;
		sort(a[i]+1,a[i]+n+1);
	}
	numnow=n;
	dfs(1,0);
	cout<<ans;
}
