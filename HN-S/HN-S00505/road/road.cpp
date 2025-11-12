#include<bits/stdc++.h>
using namespace std;
int n,m,k,rdn;
long long ans;
int fa[10001];
int js[10001][10001];
int bvs[10001];
bool b[10001];
bool B[10001][10001];
bool v_c[10001][10001];
struct rd{
	int u;
	int v;
	int w;
	int tjd;
}rds[1000001];
bool cmp(rd a1,rd a2){
	return a1.w <a2.w;
}
int find(int x){
	if(fa[x]=x) return x;
	else return fa[x]=find(fa[x]);
}
long long djstl(){
	int cnt=0;
	for(int i=1;i<=rdn;++i){
		int u=find(rds[i].u);
		int v=find(rds[i].v);
		if(u==v) continue;
		fa[u]=v;
		cnt++;
		if(rds[i].tjd!=0){
			if(!v_c[rds[i].tjd][u] && !v_c[rds[i].tjd][v]){
				ans+=rds[i].w;
				v_c[rds[i].tjd][u]=v_c[rds[i].tjd][v]=1;
			}
			else if(!v_c[rds[i].tjd][u] && v_c[rds[i].tjd][v]){
				ans+=js[rds[i].tjd][u];
				v_c[rds[i].tjd][u]=1;
			}
			else{
				ans+=js[rds[i].tjd][v];
				v_c[rds[i].tjd][v]=1;
			}
		}
		else{
			ans+=rds[i].w ;
		}
		if(cnt==n-1){
			return ans;
		}
	}
	return -1;
}
void zl(int vi){
	int l=1;int r=1;
	for(r=1;r<=n;r++){
		for(l=1;l<r;l++){
			rdn++;
			rds[rdn].u =l,rds[rdn].v =r,rds[rdn].w =js[vi][l]+js[vi][r]+bvs[vi],rds[rdn].tjd =vi;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i) scanf("%d %d %d",&rds[i].u,&rds[i].v,&rds[i].w);
	rdn=m;
	for(int v=1;v<=k;++v){
		scanf("%d",&bvs[v]);
		for(int w=1;w<=n;++w){
			scanf("%d",&js[v][w]);
		}
		zl(v);
	}
	for(int i=1;i<=n+k;++i) fa[i]=i;
	sort(rds+1,rds+1+rdn,cmp);
	cout<<djstl();
	return 0;
}
