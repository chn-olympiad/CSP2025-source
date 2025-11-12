#include<bits/stdc++.h>
using namespace std;
long long ans,sum;
int n,m,k,fa[10004];
struct node{
	int f;
	int to;
	long long w;
}q[1000004];
int find(int u){
	if(fa[u]==u){
		return u;
	}
	return fa[u]=find(fa[u]);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
void K(){
	for(int i=1;i<=m;i++){
		int f1=find(q[i].f);
		int f2=find(q[i].to);
		if(f1!=f2){
			sum+=q[i].w;
		}
		fa[f1]=fa[f2];
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&q[i].f,&q[i].to,&q[i].w);
		ans+=q[i].w;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(q+1,q+m+1,cmp);
	K();
	if(k==0){
		cout<<sum;
	}
	else{
		cout<<ans;	
	}
	return 0;
}
