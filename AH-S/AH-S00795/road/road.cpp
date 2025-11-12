#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#define int ll
const int mod=1e9+7;
const int N=1e4+50;
const int M=1e6+50;
#define endl '\n'
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n,m,k;
struct edge{
	int u,v,w;
}e[M];
bool cmp1(edge &a,edge &b){
	return a.w<b.w;
}
int fa[N]={};
int parent(int x){
	return x==fa[x]?x:fa[x]=parent(fa[x]);
}
void merge(int x,int y){
	int fx=parent(x);
	int fy=parent(y);
	fa[fx]=fy;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	IO;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	//~ cout<<1<<endl;
	if(k==0){
		sort(e+1,e+m+1,cmp1);
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		//~ cout<<'y'<<endl;
		int ans=0;
		for(int i=1;i<=m;i++){
			int x=e[i].u,y=e[i].v;
			if(parent(x)!=parent(y)){
				merge(x,y);
				ans+=e[i].w;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
