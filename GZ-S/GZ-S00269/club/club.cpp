//GZ-S00269 ×ñÒåÌìÁ¢ ÑîÈó¿­  
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct num{
	int a,b,c;
}w[maxn];
int n;
int suma,sumb,sumc,mx;
int ma[maxn],mb[maxn],mc[maxn];
void dfs(int u,int a,int b,int c){
//    if(suma+sumb+sumc<ma[a]+mb[b]+mc[c]&&u!=1)return;
	ma[a]=max(ma[a],suma);
	mb[b]=max(mb[b],sumb);
	mc[c]=max(mc[c],sumc);
	
	if(u==n+1){
		mx=max(mx,suma+sumb+sumc);
		return;
	}
	
	if(a+b+c>n)return;
	for(int i=1;i<=3;++i){
		if(a<n/2){
			suma+=w[u].a;
			dfs(u+1,a+1,b,c);
			suma-=w[u].a;
		}
		if(b<n/2){
			sumb+=w[u].b;
			dfs(u+1,a,b+1,c);
			sumb-=w[u].b;
		}
		if(c<n/2){
			sumc+=w[u].c;
			dfs(u+1,a,b,c+1);
			sumc-=w[u].c;
		}
	}
}

void rink(){
	suma=sumb=sumc=0,mx=-1;
	memset(ma,0,sizeof ma);
	memset(mb,0,sizeof mb);
	memset(mc,0,sizeof mc);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d%d%d",&w[i].a,&w[i].b,&w[i].c);
//    sort(a+1,a+n+1,cmpa);
//    int ans=0;
//    for(int i=1;i*2<=n;++i)ans+=a[i].a;
//    printf("%d\n",ans);
    dfs(1,0,0,0);
    printf("%d\n",mx);
}
	
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		rink();
	}
	return 0;
}
