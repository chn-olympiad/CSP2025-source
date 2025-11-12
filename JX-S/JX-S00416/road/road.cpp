#include<bits/stdc++.h>
using namespace std;
struct bian{
	int u;
	int v;
	long long w;
};
int n,m,k,cnt=0;
long long ans=0;
int f[1100000];
bian t[1100000],a[110000],g[11000][20];
long long mmin(long long x,long long y){
	if(x<y){
		return x;
	}else{
		return y;
	}
}
bool cmp(bian x,bian y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(x);
}
long long qj(int n,int m,long long num){
	long long ans=num;
	bian t[110000];
	for(int i=1;i<=n+10;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		t[i]=a[i];
	}
	sort(t+1,t+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		int xx=find(t[i].u),yy=find(t[i].v);
		if(yy!=xx){
			f[yy]=xx;
			cnt++;
			ans+=t[i].w;
		}
		if(cnt==n-1){
			break;
		}
	}
	return ans;
}
void dfs(int x,int cnt,int p,long long num){
	if(x==k+1){
		return;
	}
	for(int i=1;i<=n;i++){
		a[cnt+i]=g[x][i];
	}
	ans=mmin(ans,qj(n+p+1,n+cnt,num+g[x][0].w));
	dfs(x+1,cnt+n,p+1,num+g[x][0].w);
	ans=mmin(ans,qj(n+p,cnt,num));
	dfs(x+1,cnt,p,num);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&t[i].u,&t[i].v,&t[i].w);
	}
	sort(t+1,t+1+m,cmp);
	for(int i=1;i<=m;i++){
		int xx=find(t[i].u),yy=find(t[i].v);
		if(yy!=xx){
			f[yy]=xx;
			cnt++;
			a[i]=t[i];
			ans+=t[i].w;
		}
		if(cnt==n-1){
			break;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			g[i][j].u=j;
			g[i][j].v=n+i;
			scanf("%lld",&g[i][j].w);
		}
	}
	dfs(1,n-1,0,0);
	printf("%lld",ans);
	return 0;
}
