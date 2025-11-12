#include<bits/stdc++.h>
using namespace std;//¿ªlonglong 
const int N=1e4+5;
const int M=2e6+5;
int n,m,k;
struct node{
	int u,v;
	long long w;
};
node s[M];
long long a[N];
int fa[N];
int find(int k){
	if(fa[k]==k) return k;
	else return fa[k]=find(fa[k]);
}
void merge(int g,int h){
	int gt=find(g),ht=find(h);
	if(gt<ht){
		fa[ht]=gt;
	}else{
		fa[gt]=ht;
	}
	return;
}
bool cmp(node g,node h){
	return g.w<h.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v;
		long long w;
		cin>>u>>v>>w;
		s[i].u=u;
		s[i].v=v;
		s[i].w=w;
	}
	int tot=m;
	for(int i=1;i<=k;i++){
		long long x;
		cin>>x;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				s[++tot].u=u;
				s[tot].v=v;
				s[tot].w=a[v]+a[u]+x;
			}
		}
	}
	sort(s+1,s+tot+1,cmp);
	long long ans=0;
	int cnt=0;
	for(int i=1;i<=tot;i++){
		int u=s[i].u;
		int v=s[i].v;
		long long w=s[i].w;
		if(find(u)==find(v)) continue;
		merge(u,v);
		ans+=w*1LL;
		cnt++;
		if(cnt==n-1){
			break;
		}
	}
	cout<<ans;
	return 0; 
} 
