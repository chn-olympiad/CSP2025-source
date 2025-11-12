#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[1008][1008],fa[2008],dis[1008][1008]={0};
struct name{
	int u,v,w;
};
vector<name>a;
bool cmp(name x,name y){
	return x.w<y.w;
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void un(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		fa[x]=y;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		name e;
		scanf("%d %d %d",&e.u,&e.v,&e.w);
		a.push_back({e.u,e.v,e.w});
		dis[e.u][e.v]=dis[e.v][e.u]=min(dis[e.u][e.v],e.w);
	}
	int cnt=m;
	for(int i=1;i<=k;i++){
		int f;
		cin>>f;
		if(f==0){
			for(int j=1;j<=n;j++){
				scanf("%d",&c[i][j]);
			}
			for(int j=1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(c[i][j]+c[i][k]<dis[i][j]){
						dis[i][j]=dis[j][i]=c[i][j]+c[i][k];
						a.push_back({j,k,c[i][j]+c[i][k]});
					}
				}
			}
		}
		else{
			for(int j=1;j<=n;j++){
				scanf("%d",&c[i][j]);
			}
		}
	} 
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(a.begin(),a.end(),cmp);
	long long sum=0,ans=0;
	for(int i=0;i<a.size();i++){
		int u=a[i].u;
		int v=a[i].v;
		int w=a[i].w;
		if(find(u)!=find(v)){
			un(u,v);
			sum++;
			ans+=w;
			if(sum==n-1){
				cout<<ans<<endl;
				return 0;
			}
		}
	}
	return 0;
} 
