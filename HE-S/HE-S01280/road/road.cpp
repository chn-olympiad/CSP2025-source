#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
const int M = 5e6+10;
int n,m,k;
struct Edge{
	int u,v;ll w;
	bool operator < (const Edge &x)const{
		return w<x.w;
	}
}e[M],d[M];int cnt=0;
ll c[N],a[12][N];
int fa[N];ll res=1e18,ans=0;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void kruskal(int num){
	for(int i=1;i<=cnt;i++)d[i]=e[i];
	for(int i=1;i<=num;i++) fa[i]=i;
	sort(d+1,d+1+cnt);int sum=0;
	for(int i=1;i<=cnt;i++){
		int u=d[i].u,v=d[i].v;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		fa[fu]=fv;ans+=d[i].w;sum++;
		if(sum==num-1) break;
	}
	if(sum==num-1) res=min(res,ans);
}
void SubA(){
	for(int i=0;i<=(1<<k)-1;i++){
		i=(1<<k)-1;
		int num=n;ans=0;cnt=m;
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				num++;ans+=c[j];
				for(int u=1;u<=n;u++){
					e[++cnt]={num,u,a[j][u]};
				}
			}
		}
		if(ans<res){
			kruskal(num);
		}
	}
	cout << res << '\n';
}
bool f=1;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;ll w;cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) f=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(f){SubA();return 0;}
	for(int i=0;i<=(1<<k)-1;i++){
		int num=n;ans=0;cnt=m;
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				num++;ans+=c[j];
				for(int u=1;u<=n;u++){
					e[++cnt]={num,u,a[j][u]};
				}
			}
		}
		if(ans<res){
			kruskal(num);
		}
	}
	cout << res << '\n';
	return 0;
}
