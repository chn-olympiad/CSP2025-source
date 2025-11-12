#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
const int N=1e6+10;
const ll INF=1e18;
int n,m,k,i,j,xi,yi,tot,curk[11],curkcnt,pl,pr,fa[10100],idx,b;
ll c[N],ans[1024],finans;
struct edge{
	int u,v;
	ll w;
}a[N],ka[11][10010],sta[1024][10100],cl,cr;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int father(int u){
	if(fa[u]==u) return u;
	fa[u]=father(fa[u]);
	return fa[u];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	finans=INF;
	for(i=1;i<=m;++i) scanf("%d%d%lld",&a[i].u,&a[i].v,&a[i].w);
	sort(a+1,a+1+m,cmp);
	for(i=1;i<=n;++i) fa[i]=i;
	for(i=1,idx=0;i<=m;++i){
		xi=father(a[i].u),yi=father(a[i].v);
		if(xi!=yi){
			fa[yi]=xi;
			sta[0][++idx]=a[i];
			ans[0]+=a[i].w;
		}
	}
	sta[0][n+1].w=INF;
	finans=ans[0];
	//cout<<ans[0]<<"\n";
	for(i=1;i<=k;++i){
		scanf("%lld",&c[i]);
		for(j=1;j<=n;++j){
			scanf("%lld",&ka[i][j].w);
			ka[i][j].u=n+i,ka[i][j].v=j;
		}
		sort(ka[i]+1,ka[i]+1+n,cmp);
		ka[i][n+1].w=INF;
	}
	tot=(1<<k);
	for(i=1;i<tot;++i){
		curkcnt=0;
		for(j=0;j<k;++j){
			if((i&(1<<j))>0) curk[++curkcnt]=j+1;
		}
		b=(i^(1<<(curk[1]-1)));
		pl=pr=idx=0;
		for(j=1;j<=n+10;++j) fa[j]=j;
		while(idx<n+curkcnt-1){
			cl=sta[b][pl+1],cr=ka[curk[1]][pr+1];
			if(cl.w<cr.w){
				++pl;
				xi=father(cl.u),yi=father(cl.v);
				if(xi!=yi){
					fa[yi]=xi;
					ans[i]+=cl.w;
					sta[i][++idx]=cl;
				}
			}else{
				++pr;
				xi=father(cr.u),yi=father(cr.v);
				if(xi!=yi){
					fa[yi]=xi;
					ans[i]+=cr.w;
					sta[i][++idx]=cr;
				}
			}
		}
		for(j=1;j<=curkcnt;++j) ans[i]+=c[curk[j]];
		finans=min(finans,ans[i]);
		sta[i][idx+1].w=INF;
		//cout<<i<<' '<<ans[i]<<"\n";
	}
	printf("%lld\n",finans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//15:49-16:46-17:08
