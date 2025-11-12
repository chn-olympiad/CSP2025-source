#include<bits/stdc++.h>
using namespace std;
int fa[100000];
int f[20];
int f2[20][100000];
bool use[100];
int n,m,k;
struct ed{
	int x,y,z;
	bool operator<(const ed &ano)const{
		return z>ano.z;
	}
};
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
bool merge(int x,int y){
	int g1=find(x),g2=find(y);
	if(g1==g2){
		return 0;
	}
	fa[g1]=g2;
	return 1;
}
ed bian[1000000];
long long kru(int sl,priority_queue<ed> q2){
	long long lans=0;
	while(sl>1){
		auto t=q2.top();
		q2.pop();
		if(merge(t.x,t.y)){
			lans+=t.z;
			sl--;
		}
	}
	return lans;
}
long long ans=0;
void dfs(int sl,long long hf){
	if(sl==k+1){
		priority_queue<ed> q2;
		for(int i=1;i<=m;i++){
			q2.push(bian[i]);
		}
		int ji=0;
		for(int i=1;i<=k;i++){
			if(use[i]==1){
				ji++;
				for(int j=1;j<=n;j++){
					q2.push({n+ji,j,f2[i][j]});
				}
			}
		}
		for(int i=1;i<=n+ji;i++){
			fa[i]=i;
		}
		long long dans=hf+kru(n+ji,q2);
		ans=min(ans,dans);
		return;
	}
	dfs(sl+1,hf);
	use[sl]=1;
	dfs(sl+1,hf+f[sl]);
	use[sl]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	scanf("%d %d %d",&n,&m,&k);
	if(k==0){
		priority_queue<ed> q;
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=m;i++){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			q.push({a,b,c});
		}
		int z=n;
		while(z>1){
			auto t=q.top();
			q.pop();
			if(merge(t.x,t.y)){
				ans+=t.z;
				z--;
			}
		}
		printf("%lld",ans);
	}
	else if(k<=5){
		for(int i=1;i<=m;i++){
			scanf("%d %d %d",&bian[i].x,&bian[i].y,&bian[i].z);
		}
		for(int i=1;i<=k;i++){
			scanf("%d",&f[i]);
			for(int j=1;j<=n;j++){
				scanf("%d",&f2[i][j]);
			}
		}
		ans=1e18;
		dfs(1,0);
		printf("%lld",ans);
	} 
	else{
		priority_queue<ed> q;
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=m;i++){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			q.push({a,b,c});
		}
		for(int i=1;i<=k;i++){
			scanf("%d",&f[i]);
			for(int j=1;j<=n;j++){
				scanf("%d",&f2[i][j]);
			}
		}
		int z=n;
		while(z>1){
			auto t=q.top();
			q.pop();
			if(merge(t.x,t.y)){
				ans+=t.z;
				z--;
			}
		}
		printf("%lld",ans);
	}
	return 0;
} 
