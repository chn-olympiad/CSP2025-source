#include<bits/stdc++.h>
#define N 10110
#define M 110010
using namespace std;
int n,m,k,c[20],a[20][N],fa[N],ans=0,rdn,vis[20],rrd[20],costr[20];
struct Rd{
	int u,v,w,tip=0;
}rd[N];
queue<Rd> qu[20];
bool cmp(Rd a,Rd b){
	return a.w<b.w;
}
int Fa(int x){
	if(fa[x]==x) return x;
	else return fa[x]=Fa(fa[x]);
}
void joinfa(int a,int b){
	fa[Fa(a)]=Fa(b);
}
bool samefa(int a,int b){
	return Fa(a)==Fa(b);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	rdn=m;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&rd[i].u,&rd[i].v,&rd[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			rd[++rdn]={n+i,j,a[i][j]+c[i],-i};
			rd[++rdn]={n+i,j,a[i][j],i};
		}
	}
	sort(rd+1,rd+rdn+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=k;i++) fa[n+i]=n+i;
	for(int i=1;i<=rdn;i++){
		if(rd[i].tip>0&&!vis[rd[i].tip]){
			qu[rd[i].tip].push(rd[i]);
		}
		else if(!samefa(rd[i].u,rd[i].v)){
			joinfa(rd[i].u,rd[i].v);
			ans+=rd[i].w;
			if(rd[i].u>n) rrd[rd[i].u-n]++,costr[rd[i].u-n]+=rd[i].w;
			if(rd[i].v>n) rrd[rd[i].v-n]++,costr[rd[i].v-n]+=rd[i].w;
			if(rd[i].tip<0){
				vis[-rd[i].tip]=1;
				while(!qu[-rd[i].tip].empty()){
					Rd rd1=qu[-rd[i].tip].front();
					qu[-rd[i].tip].pop();
					if(!samefa(rd1.u,rd1.v)){
						joinfa(rd1.u,rd1.v);
						ans+=rd1.w;
					}
				}
			}
		}
	}
	for(int i=1;i<=k;i++){
		if(rrd[i]==1) ans-=costr[i];
	}
	cout<<ans;
	return 0;
}
