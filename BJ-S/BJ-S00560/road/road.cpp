#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e4+10,M=1e6+10;
struct node{
	int u,v,w;
}e[M];
int n,m,k;
ll c[11][N];
int cc[11];
int fa[N];
ll ans=0;
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		fa[fx]=fy;
	}
}
bool cmp(node nx,node ny){
	return nx.w<ny.w;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>cc[i];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];		
		}
	}	
	int cnt=1;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(cnt==n) break;
		int st=e[i].v,en=e[i].u,va=e[i].w;
		if(find(st)!=find(en)){
			merge(st,en);
			
			int l=cc[i];
			if(!l){
				ll t=va;
				for(int i=1;i<=10;i++){
					t=min(t,c[i][st]+c[i][en]);
				}
				ans+=t;
			}
			else ans+=va;
			cnt++;
		}
	}
	cout<<ans;
	return 0;
}
