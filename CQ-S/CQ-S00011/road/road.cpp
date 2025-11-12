#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}a[10005];
int c[10005];
bool cmp(node a,node b){
	return a.w<b.w;
}
int fa[10005];
int father(int a){
	if(fa[a]==a)return a;
	return fa[a]=father(fa[a]);
}
bool find(int a,int b){
	if(father(a)==father(b)){
		return 1;
	}else return 0;
}
void l(int a,int b){
	fa[father(a)]=fa[father(b)];
}
vector<int> tr[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	cin>>n>>m>>k;
	int cnt=1;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[cnt].u=u;
		a[cnt].v=v;
		a[cnt++].w=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			a[cnt].u=n+i;
			a[cnt].v=j;
			a[cnt++].w=w;
		}
	}
	n+=k;
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(a+1,a+cnt,cmp);
	int ans=0;
	//cout<<'\n';
	for(int i=1;i<=n;i++){
		if(!find(a[i].u,a[i].v)){
			l(a[i].u,a[i].v);
			ans+=a[i].w;
			//cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<'\n';
		}
	}
	cout<<ans;
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/
