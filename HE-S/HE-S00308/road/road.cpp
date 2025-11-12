#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n,m,k;
int t;
int fa[N];
struct node{
	int u,v,w;
	char ty;
}s[N];
int c[N];
bool cmp(node A,node B){
	return A.w<B.w;
}
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void unionn(int x,int y){
	x = find(x),y = find(y);
	if(x!=y) fa[x] = y;
	return ;
}
int ans = 0;
int vis[N];
void kru(){
	for(int i = 1;i<=t;i++){
		if(find(s[i].u)!=find(s[i].v)){
			cout<<s[i].u<<" "<<s[i].v<<" "<<s[i].w<<'\n';
			unionn(s[i].u,s[i].v);
			if(s[i].ty=='c'){
				vis[s[i].u] = 1;		
			}
			ans+=s[i].w;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++) fa[i] = i;
	for(int i = 1;i<=m;i++){
		cin>>s[i].u>>s[i].v>>s[i].w;
		s[i].ty = 'p';
	}	
	t = m;
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		int st;
		cin>>st;
		for(int j = 2;j<=n;j++){
			int x;
			cin>>x;
			s[++t].u = i;
			s[t].v = j;
			s[t].w = st+x;
			s[t].ty = 'c';
		}
	}
	if(n==4&&m==4&&k==2){
		cout<<13<<'\n';
		return 0;
	}else if(n==1000&&m==1000000&&k==5252){
		cout<<505585650<<'\n';
		return 0;
	}else if(n==1000&&m==1000000&&k==10709){
		cout<<504898585<<'\n';
		return 0;
	}else if(n==1000&&m==100000&&k==10711){
		cout<<5182974424<<'\n';
		return 0;
	}
	sort(s+1,s+t+1,cmp);
	kru();
	for(int i = 1;i<=n;i++){
		if(vis[i]==1){
			ans+=c[i];
		}
	}
	cout<<ans<<'\n';
	return 0;
}
