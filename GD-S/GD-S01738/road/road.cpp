#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+15;
const int maxm=2e6+5;
//?Maybe only MST......in special A and 1~4
//1e6 mlogm?it's a bit diffiult though 
struct edg{int u,v,w;}ed[maxm];
int n,m,k;
long long ans;
int c[maxn];
bool cmp(edg x,edg y){
	return x.w<y.w;
}
int bfa[maxn],bsz[maxn];
int getf(int x){
	return (x==bfa[x]?x:bfa[x]=getf(bfa[x]));
}
void un(int x,int y){
	int u=getf(x),v=getf(y);
	if(bsz[u]<bsz[v])swap(u,v);
	bfa[v]=u;
	bsz[u]+=bsz[v];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		ed[i]={u,v,w};
	}
/*
6 10 3
1 2 3
2 3 4
3 4 5
4 5 6
5 6 7
6 1 8
1 3 9
2 4 10
3 5 11
4 6 12
0 3 0 4 5 6 7
0 3 4 0 5 6 7
0 3 4 5 0 6 7
*/
	for(int i=1;i<=k;i++){
		cin>>c[i-n];
		if(c[i-n]==0){
			vector<int> v;
			int x=0;
			for(int j=1;j<=n;j++){
				int w;
				cin>>w;
				if(w==0)x=j;
				v.push_back(w);
			}
			for(int j=0;j<v.size();j++){
				if(x==j+1)continue;
				ed[++m]={x,j+1,v[j]};
			}
		}
//		for(int j=1;j<=n;j++){
//			int w;
//			cin>>w;
//			ed[i]={i,j,w};
//		}
	}
	sort(ed+1,ed+m+1,cmp);
	for(int i=1;i<=n+k;i++){
		bfa[i]=i;
		bsz[i]=1;
	}
	for(int i=1;i<=m;i++){
		int u=ed[i].u,v=ed[i].v,w=ed[i].w;
		int fu=getf(u),fv=getf(v);
		if(fu!=fv){
			un(u,v);
			ans+=w;
		}
	}
	cout<<ans<<endl;
	return 0;
}
