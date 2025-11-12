#include<bits/stdc++.h>
using namespace std;
const int N=1e4+50, M=2e6;
int n, m, k, x, y, z, c; 
long long ans=1e18;
int f[N], a[N], pay[N];
struct AB{
	int x, y, z;
}d[M];
bool cmp(AB a,AB b){
	return a.z<b.z;
}
int find(int x){
	if(f[x]!=x){
		return f[x]=find(f[x]);
	}
	return x;
}
long long solve(){
	long long s=0;
	int cnt=n+k, tot=m+n*k;
	for(int i=1;i<=cnt;i++) f[i]=i;
	for(int i=1;i<=tot;i++){
		if(!a[d[i].x]||!a[d[i].y])continue;
		int o=find(d[i].x), p=find(d[i].y);
		if(o!=p){
			f[o]=p;
			s+=d[i].z;
		}
	}
	return s;
	
}
void dfs(int t,long long s){
	if(t>k){
		ans=min(ans,s+solve());
		return;
	}
	a[n+t]=0;
	dfs(t+1,s);
	a[n+t]=1;
	dfs(t+1,s+pay[t]);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		d[i].x=x,d[i].y=y,d[i].z=z;
	}
	sort(d+1,d+1+m,cmp);
	for(int i=1;i<=k;i++){
		scanf("%d",&pay[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&c);
			int op=m+(i-1)*n+j;
			d[op].x=n+i,d[op].y=j,d[op].z=c;
		}
	}
	for(int i=1;i<=n;i++)a[i]=1;
	sort(d+1,d+m+n*k+1,cmp);
	dfs(1,0);
	printf("%lld",ans);
	return 0;
} 
