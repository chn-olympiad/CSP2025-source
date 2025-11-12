#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans=0x3f3f3f;
int fa[1010],g[15][1010],c[15];
struct Node{
	int u,v,w;
}a[1100010],b[1100010];
bool cmp(Node A,Node B){
	return A.w<B.w;
}
int find(int x){
	if(x!=fa[x]) return fa[x]=find(fa[x]);
}
void add(int x,int y){
	fa[find(y)]=find(x);
}
void dfs(int nowk,Node s[],int l,int d){
	if(nowk==k+1&&l==m){
		int sum=0;
		for(int i=1;i<=l;i++) fa[i]=i;
		sort(s+1,s+1+l,cmp);
		for(int i=1;i<=l;i++){
			if(find(s[i].u)!=find(s[i].v)){
				add(s[i].u,s[i].v);
				sum+=s[i].w;
			}
			if(sum>ans) break;
		}
		//cout<<sum<<"***"<<nowk<<endl;
		ans=min(ans,sum);
		return;
	}
	if(nowk==k+1) return;
	for(int i=1;i<=l;i++){
		b[i].u=s[i].u; b[i].v=s[i].v; b[i].w=s[i].w;
	}
	dfs(nowk+1,b,l,d+1);
	int sum=c[nowk];
	for(int i=1;i<=n;i++) s[l+i].u=d+1,s[l+i].v=i,s[l+i].w=g[nowk][i];
	l+=n;
	sort(s+1,s+1+l,cmp);
	for(int i=1;i<=l;i++) fa[i]=i;
	//for(int i=1;i<=l;i++) cout<<s[i].u<<" "<<s[i].v<<" "<<s[i].w<<endl;
	for(int i=1;i<=l;i++){
		if(find(s[i].u)!=find(s[i].v)){
			add(s[i].u,s[i].v);
			sum+=s[i].w;
			//cout<<s[i].u<<" "<<s[i].v<<" "<<s[i].w<<endl;
		}
		if(sum>ans) break;
	}
	//cout<<sum<<"###"<<nowk<<endl;
	ans=min(ans,sum);
	dfs(nowk+1,s,l,d+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[i].u=u,a[i].v=v,a[i].w=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>g[i][j];
	}
	sort(a+1,a+1+m,cmp);
	dfs(1,a,m,n);
	cout<<ans;
	return 0;
}
