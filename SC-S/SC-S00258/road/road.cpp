#include<bits/stdc++.h>
using namespace std;
int fa[10001];
int n,m,k;
struct node{
	int a;
	int b;
	int w;
}p[1000001];
bool cmp(node x,node y){
	return x.w<y.w;
} 
int find(int u){
	if(u=fa[u]){
		return u;
	}else{
		return fa[u]=find(fa[u]);
	}
}
void uni(int u,int v){
	u=find(u);
	v=find(v);
	if(u!=v){
		fa[v]=u;
	}
} 
bool check(int u,int v){
	u=find(u);
	v=find(v);
	if(u==v){
		return false;
	}else{
		return true;
	}
}
int xx,yy;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>xx>>yy>>p[i].w;
		p[i].a=min(xx,yy);
		p[i].b=max(xx,yy);
	} 
	sort(p+1,p+m+1,cmp);
	long long ans=0;
	int sum=0;
	for(int i=1;i<=m;i++){
		if(sum==n-1){
			break;
		}
		if(check(p[i].a,p[i].b)){
			ans+=p[i].w;
			uni(p[i].a,p[i].b);
			sum++;
			
		}
	}
	cout<<ans;
	return 0;
} 