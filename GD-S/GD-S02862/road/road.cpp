#include<bits/stdc++.h>
#define N 1000005
using namespace std;
long long ans;
bool vis[15];
int fa[N],n,m,k,c[15],ts[15][N];
struct edge{
	int u1,u2;
	long long pos;
	bool flag=0; 
}g[2000005];//5000000
bool cmp(edge x,edge y){
	return x.pos<y.pos;
}
int find(int s){
	if(fa[s]==s)return s;
	else return fa[s]=find(fa[s]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&g[i].u1,&g[i].u2,&g[i].pos);
	}
	for(int i=1;i<=n+k;i++)fa[i]=i;
	int tp;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&ts[i][j]);
		}
	}
	sort(g+1,g+1+m,cmp);
	for(int i=1;i<=m;i++){
		int e1=find(g[i].u1);
		int e2=find(g[i].u2);
		if(e1==e2)continue;
		fa[e1]=e2;
		ans+=g[i].pos;
		g[i].flag=1;
	}
	long long post;
	for(int i=1;i<=m;i++){
		if(g[i].flag==0)continue;
		int e1=g[i].u1,e2=g[i].u2;
		for(int j=1;j<=k;j++){
			if(vis[j])post=0;
			else post=c[j];
			long long post2=ts[j][e1]+ts[j][e2]+post;
			if(g[i].pos>=post2){
				ans-=(g[i].pos-post2);
				vis[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
