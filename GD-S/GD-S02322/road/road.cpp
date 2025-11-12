#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int u,v,w;
}e[10005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int n,m,k,ans=2e9,q;
int c[15],fa[10005];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void kru(){
	int sum=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x!=y){
			fa[x]=y;
			sum+=e[i].w;
		}
	}
	ans=min(ans,sum);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	kru();
	q=m+1,m=m+n;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		int b,num=0;
		for(int j=q;j<=m;j++){
			cin>>b;
			e[j]={n+1,++num,b};
		}
		q=m+1,m+=n;
	}
	kru();
	cout<<ans;
	return 0;
}
