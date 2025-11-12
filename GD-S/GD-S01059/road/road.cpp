#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
const int N=1e4+10;
const int M=11;
int n,m,k,u,v,w,cnt,ans;
int fa[N],cont[M][N];
struct edge{
	int u,v,w;
};
vector<edge> t;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int found(int x){
	if(fa[x]==x) return x;
	return fa[x]=found(fa[x]);
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		t.push_back(edge{u,v,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",cont[i][0]);
		for(int j=1;j<=n;j++){
			scanf("%lld",cont[i][j]);
		}
		for(int j=1;j<=n;j++){
			for(int l=j+1;l<=n;l++){
				t.push_back(edge{j,l,cont[i][j]+cont[i][l]});
			}
		}
	}
	sort(t.begin(),t.end(),cmp);
	for(int i=0;i<t.size();i++){
		u=t[i].u,v=t[i].v,w=t[i].w;
		int faU=found(u),faV=found(v);
		if(faU!=faV){
			fa[faU]=faV;
			cnt++;
			ans+=w;
		}
		if(cnt==n-1) break; 
	}
	printf("%lld",ans); 
	return 0;
} 
