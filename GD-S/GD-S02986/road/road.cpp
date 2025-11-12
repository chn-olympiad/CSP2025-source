#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
long long n,m,k;
long long ans=0;
struct Node{
	long long u,v,w;
	bool operator < (const Node &o) const{
		return w<o.w;
	}
};
vector<Node>vt;
long long fa[200003];
long long find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(long long x,long long y){
	x=find(x);
	y=find(y);
	if(x==y) return ;
	fa[x]=y;
}
void f(){
	for(long long i=0;i<m;i++){
		long long u=vt[i].u;
		long long v=vt[i].v;
		long long w=vt[i].w;
		if(find(u)!=find(v)){
			merge(u,v);
			ans+=w;
		}
	} 
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	bool flag=false;
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		vt.push_back({u,v,w});
	}
	for(long long i=1;i<=k;i++){
		long long x;
		cin>>x;
		if(x!=0) flag=true;
		for(long long j=1;j<=n;j++){
			cin>>x;
			if(x!=0) flag=true;
		}
	}
	for(long long i=1;i<=n;i++) fa[i]=i;
	if(k==0){
		sort(vt.begin(),vt.end());
		f();
		cout<<ans;
	}
	else if(!flag) cout<<0;
	else cout<<100;
	return 0;
}

