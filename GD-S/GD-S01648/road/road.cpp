#include<bits/stdc++.h>
using namespace std;
const int maxm=2e6+10,maxn=1e4+20;
int n,m,k,tot=0,C[11],use=0,fa[maxn];
long long ans=0x3f3f3f3f3f3f3f3f;
struct date{
	int a,b,c;
	bool operator<(const date r)const{
		return c<r.c;
	}
}road[maxm];
int find(int u){
	return fa[u]==u?u:fa[u]=find(fa[u]);
}
void uni(int a,int b){
	int faa=fa[a],fab=fa[b];
	fa[faa]=fab;
	return;
}
void solve(){
	for(int use=0;use<=((1<<k)-1);use++){
		long long a=0;
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
		}
		for(int i=1;i<=tot;i++){
			if(road[i].b>n&&!(1<<(road[i].b-n-1)&use))continue;
			if(find(road[i].a)!=find(road[i].b)){
				uni(road[i].a,road[i].b);
				a+=road[i].c;
			}
		}
		for(int i=1;i<=k;i++){
			if(use&(1<<(i-1)))a+=C[i];
		}
		ans=min(ans,a);
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		tot++;
		scanf("%d%d%d",&road[tot].a,&road[tot].b,&road[tot].c);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&C[i]);
		for(int j=1;j<=n;j++){
			int a;
			scanf("%d",&a);
			tot++;
			road[tot].a=j,road[tot].b=i+n,road[tot].c=a;
		}
	}
	sort(road+1,road+tot+1);
	solve();
	cout<<ans;
}
