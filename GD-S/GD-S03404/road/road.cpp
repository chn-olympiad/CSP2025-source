#include<bits/stdc++.h>
//#define pii pair<int,int> 
using namespace std;
const int N=1e6+114;
struct E{
	int u,v,w;
}e[N],g[114][N];
int n,m,k,l,ans=0x3f3f3f3f,f[N],c[N];
int find(int x){
	while(x!=f[x]) x=f[x];
	return x;
}
int kru(){
	for(int i=1;i<=l;i++){
		f[i]=i;
	}
	int ans1=0,cnt=0;
	for(int i=1;i<=l;i++){
		int fu=find(e[i].u);
		int fv=find(e[i].v);
		if(fu==fv) continue;
		f[fu]=fv;
		ans1+=e[i].w;
		cnt++;
		
		if(cnt==n-1) break;
	} 
	return ans1;
}
bool cmp(E a,E b){
	return a.w<b.w;
}
//void dfs(int u,int r){
//	if(u==k+1){
//		sort(e+1,e+l+1,cmp);
//		ans=min(ans,kru(r)+r);
//		cout<<ans<<endl;
//		return ;
//	}
//	dfs(u+1,r);
//	for(int i=1;i<=n;i++){
//		e[++l]=g[u][i];
//	}
//	dfs(u+1,r+c[u]);
//	for(int i=1;i<=n;i++){
//		e[--l]={0,0,0};
//	}
//}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<N;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[++l]={u,v,w};
	}
	bool isa=1;
	for(int i=1;i<=k;i++){
		int x;
		cin>>c[i];
		if(c[i]) isa=0;
		for(int j=1;j<=n;j++){
			cin>>x;
			if(x) isa=0;
		}
	}
	if(!k) isa=0;
	if(isa){
		cout<<0;
		return 0;
	} 
	sort(e+1,e+l+1,cmp);
	cout<<kru();
	return 0;
}
/*
4 4 3
1 4 6
2 3 7
4 2 5
4 3 4
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0
0 0 0 0 0 
*/
