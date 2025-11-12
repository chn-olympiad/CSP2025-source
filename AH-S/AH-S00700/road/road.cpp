#include<bits/stdc++.h>
#define N 2000005
#define ll long long
using namespace std;
int n,m,k,c[20],cost[20],p[20][N],fa[N];
ll ans=1e18;
struct node{
	int u,v,w;
}a[N],b[N];
bool cmp(const node&x,const node&y){
	return x.w<y.w;
}
int get(int x){
	if(fa[x]!=x) fa[x]=get(fa[x]);
	return fa[x];
}
void check(ll mon){
	int nn=n,mm=m;
	for(int i=1;i<=mm;i++)
	b[i]=a[i];
	for(int i=1;i<=k;i++)
	if(cost[i]==1){
		nn++;
		for(int j=1;j<=n;j++){
			mm++;
			b[mm]={j,nn,p[i][j]};
		}
	}
	sort(b+1,b+1+mm,cmp);
	int cnt=0;ll tot=0;
	for(int i=1;i<=nn;i++) fa[i]=i;
	for(int i=1;i<=mm;i++){
		int u=get(b[i].u),v=get(b[i].v);
		if(u!=v){
			cnt++;
			tot+=b[i].w;
			fa[u]=v;
		}
		if(cnt==nn-1) break;
	}
	ans=min(ans,mon+tot);
}
void choose(int x,ll mon){
	if(x>k) {check(mon);return;}
	cost[x]=1;
	choose(x+1,mon+c[x]);
	if(c[x]!=0){
		cost[x]=0;
		choose(x+1,mon);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
		scanf("%d",&p[i][j]);
	}
	choose(1,0);
	cout<<ans;
	return 0;
}
