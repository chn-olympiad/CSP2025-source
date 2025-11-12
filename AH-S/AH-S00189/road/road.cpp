#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,m,k;
int c[15][N];
int ecnt;
struct Edge{int u,v,w;}e[N],ee[N];
bool cmp(Edge a,Edge b){return a.w<b.w;}
int fa[N];
int findfa(int x){
	if(x==fa[x])return fa[x];
	fa[x]=findfa(fa[x]);
	return fa[x];
}
bool hebing(int x,int y){
	x=findfa(x);
	y=findfa(y);
	if(x==y)return false;
	fa[x]=y;
	return true;
}
int kruskal(int tot,int now){
	sort(e+1,e+1+ecnt,cmp);
	int cnt=0;
	int ans=0;
	for(int i=1;i<=now;i++)fa[i]=i;
	for(int i=1;i<=ecnt&&cnt<tot-1;i++){
		int uu=e[i].u,vv=e[i].v,ww=e[i].w;
		if(hebing(uu,vv)){
			ans+=ww;
			cnt++;
		}
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);}
	sort(e+1,e+1+m,cmp);
	int sum=0;
	ecnt=0;
	int lst=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m&&sum<n-1;i++){
		int uu=e[i].u,vv=e[i].v,ww=e[i].w;
		if(hebing(uu,vv)){
			ee[++ecnt]={uu,vv,ww};
			lst+=ww;
		}
	}
	for(int i=1;i<=k;i++){for(int j=0;j<=n;j++){scanf("%lld",&c[i][j]);}}
	int abb=n;
	for(int i=1;i<=k;i++){
		int tmp=ecnt,now=n+i;
		for(int j=1;j<=ecnt;j++)e[j]=ee[j];
		for(int j=1;j<=n;j++){e[++ecnt]={now,j,c[i][j]};}
		abb++;
		int res=kruskal(abb,now)+c[i][0];
		abb--;
		if(res<lst){
			for(int j=1;j<=ecnt;j++)ee[j]=e[j];
			abb++;
			lst=res;
		}else{
			ecnt=tmp;
		}
	}
	printf("%lld",lst);
	return 0;
}
