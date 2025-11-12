#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5,MAXM=2e6+5;
struct node{
	int u,v;
	long long w;
	operator <(node a){return w<a.w;}
}e[MAXM];
int n,m,k,fa[MAXN],c[MAXN],a[20][MAXN],vis[MAXN],cnt,len,usd;
long long mn=2e18,ans;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y){fa[find(x)]=find(y);}
int min(int a,int b){
	if(a<b) return a;
	else return b;
}
void dfs(int x){
	if(k<x){
		vector<node> E(m);
		len=0,usd=0,cnt=0,ans=0;
		for(int i=1;i<=m;++i) E[i-1]=e[i],++len;
		for(int i=1;i<=k;++i){
			if(vis[i]){
				++usd;
				for(int j=1;j<=n;++j) E.push_back({j,n+usd,a[i][j]}),++len;
				ans=ans+c[i];
	//			cout<<i<<' ';
			}
		}
		n+=usd;
		for(int i=1;i<=n;++i) fa[i]=i;
		if(mn<ans){
			n-=usd;
			return ;
		}
	//	cout<<":"<<endl;
		sort(E.begin(),E.end());
	//	int len=E.size();
		if(mn<ans){
			n-=usd;
			return ;
		}
		for(int i=0;i<len;++i){
			if(find(E[i].u)!=find(E[i].v)) fa[find(E[i].u)]=E[i].v,ans+=E[i].w,++cnt;//cout<<i.u<<' '<<i.v<<endl;
			if(mn<ans){
				n-=usd;
				return ;
			}
			if(n==cnt+1) break;
		}
	//	mn=min(mn,ans);
	//	cout<<ans<<endl;
		if(ans<mn) mn=ans;
		n-=usd;
		return ;
	}
	if(c[x]) dfs(x+1);
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
}
int read(){
	char ch=getchar();int num=0;
	while(ch<'0' || '9'<ch) ch=getchar();
	while('0'<=ch && ch<='9') num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
	return num;
}
int main(){
//	cout<<1024*1e6*log2(1e6);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cin>>n>>m>>k;
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		e[i].u=read(),e[i].v=read(),e[i].w=read();
		if(e[i].u<e[i].v) swap(e[i].u,e[i].v);
	}
	for(int i=1;i<=k;++i){
		c[i]=read();
		for(int j=1;j<=n;++j) a[i][j]=read();
	}
	dfs(1);
	cout<<mn<<endl;
	return 0;
}
