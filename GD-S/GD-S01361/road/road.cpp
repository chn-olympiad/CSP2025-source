#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> fa;
int n,m,k;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void join(int u,int v){
	int a=find(u);
	int b=find(v);
	if(a!=b){
		fa[a]=b;
	}
}
struct node{
	int u;
	int v;
	int w;
};
bool cmp(node x,node y){
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cin>>n>>m>>k;
	fa.resize(n+15);
	std::vector<node> a(m);
	std::vector<int> cost(k+1);
	std::vector<std::vector<int>> c(k+1,std::vector<int>(n+1)); 
	for(int i=0;i<m;i++) std::cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		std::cin>>cost[i];
		for(int j=1;j<=n;j++){
			//if(j==i) j++;
			std::cin>>c[i][j];
		}
		if(cost[i]==0){
			for(int j=1;j<=n;j++) a.push_back((node){n+k,j,c[i][j]});
		}
	}
	long long ans=0;
	for(int i=1;i<=n+10;i++) fa[i]=i;
	std::sort(a.begin(),a.end(),cmp);
	for(int i=0;i<a.size();i++){
		int u=a[i].u;
		int v=a[i].v;
		int p=find(u);
		int q=find(v);
		if(p!=q){
			ans+=a[i].w;
			join(p,q);
		}
	}
	for(int i=1;i<=k;i++){
		if(cost[i]==0) continue;
		long long cur=cost[i];
		std::vector<node> b;
		for(int j=0;j<a.size();j++) b.push_back(a[j]);
		for(int j=1;j<=n;j++) b.push_back((node){n+k,j,c[i][j]});
		for(int j=1;j<=n+10;j++) fa[j]=j;
		std::sort(b.begin(),b.end(),cmp);
		for(int j=0;j<b.size();j++){
			int u=b[j].u;
			int v=b[j].v;
			int p=find(u);
			int q=find(v);
			if(p!=q){
				//std::cout<<p<<' '<<q<<'\n'; 
				cur+=b[j].w;
				join(p,q);
			}
		}
		//std::cout<<cur<<'\n';
		ans=std::min(ans,cur);
	}
	std::cout<<ans;
	return 0;
}
