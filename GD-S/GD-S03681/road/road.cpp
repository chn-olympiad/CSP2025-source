#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k;
vector<int>siz(N,1);
int f[N];
int sd[11][1000010];
struct node{
	int u,v,w;
}a[1000010];
bool cmp(node a,node b){
	return a.w<b.w;
}
int get(int x){
	if(f[x]==x){
		return x;
	}return f[x]=get(f[x]);
}
void merge(int u,int v){
	u=get(u),v=get(v);
	if(siz[u]>siz[v])swap(u,v);
	f[u]=v;
	siz[v]+=siz[u];
}
bool same(int a,int b){
	return get(a)==get(b);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		a[i].u=u,a[i].v=v,a[i].w=w;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++)cin>>sd[i][j];
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		if(!same(a[i].u,a[i].v)){
			merge(a[i].u,a[i].v);
			ans+=a[i].w;
//			cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<endl;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
