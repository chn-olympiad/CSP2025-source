#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=2e6+5,MAXM=10+5,MAXK=1e4+5,inf=1e18+5;
struct node{
	ll x,y,z,id;
};
ll n,m,k;
ll ans=inf;
ll c[MAXM];
ll a[MAXM][MAXK];
int id[MAXN];
int f[MAXK];
node e[MAXN],tmp[MAXN];
bool flag[MAXN];
int cnt=0;
bool cmp(node x,node y){
	return x.z<y.z;
}
void init(){
	for(int i=m+1;i<MAXN;i++){
		flag[i]=false;
	}
	for(int i=1;i<=MAXK;i++){
		f[i]=i;
	}
}
int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
void solve(int x){
	init();
	ll num=0ll;
	for(int i=1;i<=k;i++){
		if((x>>(i-1))&1){
			num+=c[i];
			for(int j=1;j<=n;j++){
				flag[m+(i-1)*n+j]=true;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		if(!flag[e[i].id]){
			continue;
		}
		if(find(e[i].x)==find(e[i].y)){
			continue;
		}
		num+=e[i].z;
		if(num>=ans){
			return;
		}
		f[f[e[i].x]]=f[e[i].y];
	}
	ans=min(ans,num);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(flag,true,sizeof(flag));
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].x,&e[i].y,&e[i].z);
		e[i].id=i;
	}
	cnt=m;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			e[++cnt]={n+i,j,a[i][j],cnt};
		}
	}
	sort(e+1,e+1+cnt,cmp);
	for(int i=0;i<(1<<k);i++){
		solve(i);
	}
	printf("%lld\n",ans);
}
