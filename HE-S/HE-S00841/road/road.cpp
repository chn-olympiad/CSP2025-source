#include <bits/stdc++.h>
using namespace std;
struct node{
	int u,v,d;
}f[1001000];
int ans;
bool vis[100100];
bool cmp(node a,node b){
	return a.d<b.d;
}
int n,m,k; 
void kul(){
	for(int i=1;i<=m;i++){
		int u=f[i].u,v=f[i].v,d=f[i].d;
		if(vis[u]&&vis[v])continue;
		vis[u]=vis[v]=1;
		ans+=d;
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&f[i].u,&f[i].v,&f[i].d);
	sort(f+1,f+1+m,cmp);
	kul();
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//hope 16
