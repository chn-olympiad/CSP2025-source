#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+1e4+5;
const long long inf=1e18;
int n,m,k,c[N],fa[N],siz[N],ne[15][N];
struct node{
	long long u,v,w;
}e[M];
int get_father(int x){
	if(fa[x]==x) return x;
	return fa[x]=get_father(fa[x]);
}
void init(int x){
	for(int i=1;i<=x;i++){
		fa[i]=i;
		siz[i]=1;
	}
}
void merge(int u,int v){
	int fu=get_father(u),fv=get_father(v);
	if(siz[u]>siz[v]) swap(u,v);
	fa[fu]=fv;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
bool find(int u,int v){
	return get_father(u)==get_father(v);
}
long long mst(int x){
	sort(e+1,e+x+1,cmp);
//	for(int i=1;i<=x;i++){
//		cout<<fa[i]<<" ";
//	}
//	cout<<endl;
	long long sum=0;
	for(int i=1;i<=x;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
//		cout<<">"<<u<<" "<<v<<" "<<w<<endl;
		if(find(u,v)==false){
			sum+=w;
			merge(u,v);
		}
	}
	return sum;
}
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>ne[i][j];
		}
	}
	init(n);
	long long ans=inf;
	for(int i=0;i<(1<<k);i++){
		int tot=m,s=0,d=0;
//		cout<<"<<";
		for(int j=0;j<k;j++){
			if((i>>j)&1){
//				cout<<1;
				d+=c[j];
				s++;
				for(int l=1;l<=n;l++){
					tot++;
					e[tot]={l,n+s,ne[j][l]};
				}
			}
		}
//		cout<<endl;
		if(d>=ans) continue;
		init(n+s);
		ans=min(ans,d+mst(tot));
//		cout<<d<<" "<<ans<<endl;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/
