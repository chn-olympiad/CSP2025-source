#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,m,k,f[N],a[N];
struct Edge{
	int u,v,w;
	bool operator<(const Edge ee)const{
		return ee.w>w;
	}
}e[N<<2];
int find(int x){
	if(f[x]!=x) return f[x]=find(f[x]);
	return x;
}
void unionn(int x,int y){
	x=find(x);
	y=find(y);
	f[x]=y;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int cnt=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[++cnt]={u,v,w};
	}
	for(int q=1;q<=k;q++){
		memset(a,0,sizeof(a));
		int x;
		scanf("%d",&x);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			for(int j=1;j<i;j++){
				if(i==j) continue;
				int y=a[i]+a[j]+x;
				e[++cnt]={i,j,y};
			}
		}
	}
	
	sort(e+1,e+cnt+1);
	int ans=0;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=cnt;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v)){
			unionn(u,v);
			ans+=w;
		}
	}
	printf("%d",ans);
	return 0;
}

