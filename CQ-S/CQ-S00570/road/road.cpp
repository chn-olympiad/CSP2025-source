#include<bits/stdc++.h>
using namespace std;
const unsigned long long N=5e6+50;
unsigned long long n,m,k,tot=0,ans=0x3f3f3f3f3f3f3f3f;
unsigned long long c[N];
unsigned long long a[21][N];
struct Edges{
	Edges(){u=v=0,w=0x3f3f3f3f3f3f3f3f;}
	unsigned long long u,v,w;
}p[N],f[N];
bool cmp(Edges A,Edges B){
	return A.w<B.w;
}
struct BCJ{
	unsigned long long fa[N],sz[N];
	void init(){
		for(unsigned long long i=0;i<=n+k+1;i++){
			fa[i]=i;
			sz[i]=1;
		}
	}
	unsigned long long find(unsigned long long x){
		if(fa[x]==x)return x;
		return fa[x]=find(fa[x]);
	}
	bool merge(unsigned long long x,unsigned long long y){
		unsigned long long a=find(x),b=find(y);
		if(a==b)return false;
		if(sz[a]<sz[b])swap(a,b);
		fa[b]=a;sz[a]+=sz[b];
		return true;
	}
}bcj;
unsigned long long check(unsigned long long n,unsigned long long k){
	unsigned long long num=0;
	bcj.init();
	sort(f+1,f+n*k+1,cmp);
	unsigned long long l=1,r=1;
	for(;l<=m || r<=n*k;){
		Edges tmp;
		if(l>m){
			tmp=f[r];r++;
		}else if(r>n*k){
			tmp=p[l];l++;
		}else if(p[l].w<f[r].w){
			tmp=p[l];l++;
		}else{
			tmp=f[r];r++;
		}
		if(bcj.merge(tmp.u,tmp.v)){
			num+=tmp.w;
		}
		if(bcj.sz[bcj.find(tmp.u)]>=n+k)return num;
	}
//	cout<<bcj.sz[bcj.find(1)]<<endl;
	return num;
}
void dfs(unsigned long long dep,unsigned long long sum,unsigned long long num){
//	if(sum>ans)return ;
	if(dep>k){
		ans=min(ans,check(n,num)+sum);
		return ;
	}
	dfs(dep+1,sum,num);
	for(unsigned long long i=1;i<=n;i++){
		f[++tot].u=dep+n;
		f[tot].v=i;
		f[tot].w=a[dep][i];
	}
	dfs(dep+1,sum+c[dep],num+1);
	tot-=n;
//	cout<<tot<<endl;
//	if(tot<0)cout<<"FFF\n";
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(unsigned long long i=1;i<=m;i++){
		cin>>p[i].u>>p[i].v>>p[i].w;
	}
	sort(p+1,p+m+1,cmp);
	for(unsigned long long i=1;i<=k;i++){
		cin>>c[i];
		for(unsigned long long j=1;j<=n;j++)cin>>a[i][j];
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
} 
