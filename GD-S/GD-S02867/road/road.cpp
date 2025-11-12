#include <bits/stdc++.h>
using namespace std;
const int N=2e4+10,M=2e6+10;

struct edge{
	int u,v,x,id;
}e[M];
int n,m,k;
long long ans=1e18;
int c[20],bd[20][N],fa[N];
bool use[20];

bool cmp(edge A,edge B){
	return A.x<B.x;
}

bool inv_cmp(edge A,edge B){
	return A.id<B.id;
}

int find(int x){
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	return fa[x];
}

long long kruskal(int new_m,int new_n){
	long long res=0;
	sort(e+1,e+new_m+1,cmp);
	for(int i=1;i<=new_n;i++){
		fa[i]=i;
	}
	int  cnt=0;
	for(int i=1;i<=new_m;i++){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv) continue;
		fa[fu]=fv,res+=1ll*e[i].x;
		cnt++;
		if(cnt==new_n-1) break;
	}
	sort(e+1,e+new_m+1,inv_cmp);
	return res;
}

void make_choice(int cas){
	if(cas==k+1){
		int new_m=m,new_n=n,cost=0;
		for(int i=1;i<=k;i++){
			if(use[i]){
				new_n++;
				cost+=c[i];
				for(int j=1;j<=n;j++){
					e[++new_m].u=j,e[new_m].v=new_n,e[new_m].x=bd[i][j];
					e[new_m].id=new_m;
				}
			}
		}
		ans=min(ans,cost+kruskal(new_m,new_n));
	} 
	else{
		use[cas]=1;
		make_choice(cas+1);
		use[cas]=0;
		make_choice(cas+1); 
	}
}


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].x);
		e[i].id=i;
	}
	bool is_A=1;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]) is_A=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&bd[i][j]);
		}
	}
	if(!is_A) make_choice(1);
	else{
		int new_m=m,new_n=n,cost=0;
		for(int i=1;i<=k;i++){
			new_n++;
			cost+=c[i];
			for(int j=1;j<=n;j++){
				e[++new_m].u=j,e[new_m].v=new_n,e[new_m].x=bd[i][j];
				e[new_m].id=new_m;
			}
		}
		ans=kruskal(new_m,new_n);
	}
	printf("%lld",ans);
	
	return 0;
} 
