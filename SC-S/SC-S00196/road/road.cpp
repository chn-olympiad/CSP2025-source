#include <bits/stdc++.h>
using namespace std;
const int MAX_N=10050,MAX_M=1000010;
int n,m,k;
struct node{
	int v,w;
};
struct nnode{
	int u,v,w;
};
bool vv[MAX_N];
vector<nnode> g,h;
int c[15],a[15][MAX_N];
int f[MAX_N];
int find(int x){
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
void mat(int x,int y){
	x=find(x),y=find(y);
	f[x]=y;
}
bool check(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return 1;
	else return 0;
}
int lt=n;
bool cmp(nnode x,nnode y){
	return x.w<y.w;
}
long long ans=1e18,cnt=0;
int p[MAX_N];
void dfs(int x){
	if(x>k){
		for(int i=1;i<=n+k;i++) f[i]=i;
		cnt=0;
		int mm=m;
		lt=n;
		h.clear();
		for(int i=1;i<=k;i++){
			if(!p[i]) continue;
			cnt+=c[i];
			lt++;
			for(int j=1;j<=n;j++){
				mm++;
				h.push_back(nnode{i+n,j,a[i][j]});
			}
		}
		for(nnode v:g) h.push_back(v);
		sort(h.begin(),h.end(),cmp);
		for(nnode v:h){
			if(!check(v.u,v.v)){
				lt--;
				cnt+=v.w;
				mat(v.u,v.v);
			}
			if(lt==1) break;
		}
		ans=min(ans,cnt);
		return ;
	}
	for(int i=0;i<=1;i++){
		p[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool F=1;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		g.push_back(nnode{u,v,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0) F=0;
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n+k;i++) f[i]=i;
	if(k==0){
		sort(g.begin(),g.end(),cmp);
		ans=0;
		for(nnode v:g){
			if(!check(v.u,v.v)){
				lt--;
				ans+=v.w;
				mat(v.u,v.v);
			}
			if(lt==1) break;
		}
		printf("%lld",ans);
		return 0;
	}
	if(F){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				g.push_back(nnode{i+n,j,a[i][j]});
			}
		}
		sort(g.begin(),g.end(),cmp);
		ans=0;
		for(nnode v:g){
			if(!check(v.u,v.v)){
				lt--;
				if(v.u>n&&!vv[v.u]){
					lt++;
				}
				if(v.u>n) vv[v.u]=1;
				ans+=v.w;
				mat(v.u,v.v);
			}
			if(lt==1) break;
		}
		printf("%lld",ans);
		return 0;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
} 