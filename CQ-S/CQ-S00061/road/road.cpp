#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,o,ans,ans1,sum,flag,flag1,a[20][10100],e[20],fx,fy,fa[10100],fl[100];
struct u{
	int x,y,z;
	bool operator<(const u &w)const{
		return z<w.z;
	}
}d[2000100],ed[10100],edd[200100];
int read(){
	int x=0,f=1;
	char c=getchar();
	while('0'>c||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int find(int x){
	if(x==fa[x])return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void dfs(int x){
	if(x==k+1){
		ans1=0;
		for(int i=1;i<n;i++)edd[i]=ed[i];
		o=n-1;
		for(int i=1;i<=k;i++){
			if(fl[i]){
				ans1+=e[i];
				for(int j=1;j<=n;j++){
					edd[++o]={i+n,j,a[i][j]};
				}
			}
		}
		sort(edd+1,edd+1+o);
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1;i<=o;i++){
			fx=find(edd[i].x);fy=find(edd[i].y);
			if(fx==fy)continue;
			ans1+=edd[i].z;fa[fx]=fy;
		}
		ans=min(ans,ans1);return ;
	}
	fl[x]=1;dfs(x+1);
	fl[x]=0;dfs(x+1);
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		d[i].x=read();d[i].y=read();d[i].z=read();
	}
	for(int i=1;i<=k;i++){
		e[i]=read();flag1=1;sum+=e[i];
		for(int j=1;j<=n;j++)a[i][j]=read();
		for(int j=1;j<=n;j++){
			if(!a[i][j]){
				flag1=0;break;
			}
		}
		if(e[i]||flag1)flag=1;
	}
	if(flag){
		sort(d+1,d+1+m);ans=1e18;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			fx=find(d[i].x);fy=find(d[i].y);
			if(fx==fy)continue;
			fa[fx]=fy;ed[++o]=d[i];
		}
		dfs(1);
		printf("%lld",ans);
	}
	else{
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				d[++m]={i+n,j,a[i][j]};
			}
		}
		sort(d+1,d+1+m);
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			fx=find(d[i].x);fy=find(d[i].y);
			if(fx==fy)continue;
			fa[fx]=fy;ans+=d[i].z;
		}
		printf("%lld",ans); 
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
