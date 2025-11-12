#include<bits/stdc++.h>
using namespace std;
const int N=1e4+25,M=1e6+5;
int Fa[N];
int Fd(int x){
	if(x==Fa[x]){
		return x;
	}
	int xx=Fd(Fa[x]);
	Fa[x]=xx;
	return Fa[x];
}
void merge(int u,int v){
	int x=Fd(u),y=Fd(v);
	if(x==y)return ;
	Fa[x]=y;
	return ;
}
struct Edge{
	int u,v,op;
	long long w;
}e[M],ee[M];
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
long long c[N],w[15][N];
int fl[M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&w[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		Fa[i]=i;
	}
	sort(e+1,e+m+1,cmp);
	long long ans=1e18,sum=0;
	for(int i=1;i<=m;i++){
		if(Fd(e[i].u)!=Fd(e[i].v)){
			merge(e[i].u,e[i].v);
			fl[i]=1;
			sum+=e[i].w;
		}
	}
	ans=sum;
	//cout<<ans<<endl;
	int en=0;
	for(int i=1;i<=m;i++){
		if(fl[i]){
			++en;
			ee[en].u=e[i].u;
			ee[en].v=e[i].v;
			ee[en].w=e[i].w;
			ee[en].op=1;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			++en;
			ee[en].u=i+n;
			ee[en].v=j;
			ee[en].w=w[i][j];
			ee[en].op=2;
		}
	}
	//for(int i=1;i<=k;i++){
	//	++en;
	//	ee[en].u=n+1;
	//	ee[en].v=i;
	//	ee[en].w=c[i];
	//	ee[en].op=3;
	//}
	sort(ee+1,ee+en+1,cmp);
	for(int i=1;i<(1<<k);i++){
		for(int j=1;j<=n+k;j++){
			Fa[j]=j;
		}
		sum=0;
		for(int j=1;j<=k;j++){
			if((1<<(j-1))&i){
				sum+=c[j];
			}
		}
		for(int j=1;j<=en;j++){
			if(ee[j].op==2&&!((1<<(ee[j].u-n-1))&i)){
				continue;
			}
			if(Fd(ee[j].u)!=Fd(ee[j].v)){
				merge(ee[j].u,ee[j].v);
				sum+=ee[j].w;
				//if(i==1)cout<<j<<' '<<ee[j].u<<' '<<ee[j].v<<' '<<ee[j].w<<' '<<ee[j].op<<endl;
			}
		}
		//cout<<i<<' '<<sum<<endl;
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}
