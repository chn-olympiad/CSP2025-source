#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e15;
const int M=1000005;
const int N=10005;
struct node{
	int u,v,w;
}a[M];
bool cmp(node a,node b){
	return a.w<b.w;
}
struct tis{
	int fa[N];
	void init(int n){
		for(int i=1;i<=n;i++)fa[i]=i;
	}
	int fd(int x){
		return fa[x]==x?x:fa[x]=fd(fa[x]);
	}
	bool check(int u,int v){
		int p=fd(u),q=fd(v);
		return p==q;
	}
	void merge(int x,int y){
		int p=fd(x),q=fd(y);
		if(p==q)return ;
		fa[p]=q;
	}
}st;
int n,m,k,res,c[15],edg[15][N];
bool used[M];
void kru1(){
	sort(a+1,a+m+1,cmp);
	st.init(n);
	for(int i=1;i<=m;i++){
		int u=a[i].u,v=a[i].v;
		if(st.check(u,v))continue;
		st.merge(u,v);
		used[i]=1;
	}
}
node ed[N*10];
int kru2(int nn,int tot){
	sort(ed+1,ed+tot+1,cmp);
	int ans=0;
	st.init(nn);
	for(int i=1;i<=tot;i++){
		int u=ed[i].u,v=ed[i].v,w=ed[i].w;
		if(st.check(u,v))continue;
		st.merge(u,v);
		ans+=w;
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>edg[i][j];
	}
	kru1();
	for(int i=1,j=0;i<=m;i++){
		if(used[i])a[++j]=a[i];
	}
	int res=INF;
	for(int ss=0;ss<(1<<k);ss++){
		int tot=0,ans=0;
		for(int i=1;i<n;i++)ed[++tot]=a[i];
		for(int i=1;i<=k;i++){
			if(!(ss&(1<<(i-1))))continue;
			for(int j=1;j<=n;j++)ed[++tot]={j,i+n,edg[i][j]};
			ans+=c[i];
		}
		ans+=kru2(n+k,tot);
		res=min(res,ans);
	}
	cout<<res<<"\n";
}