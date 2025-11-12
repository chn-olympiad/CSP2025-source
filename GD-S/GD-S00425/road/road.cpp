#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[100005],cnt,cntt,t[15][10005];
long long ans=1e18;
struct pio{
	int u,v,w;
}z[1000005],p[1000005],q[1000005];
bool cmd(pio a,pio b){
	return a.w<b.w;
}
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
void kruskal(long long anss,int qq){
	if(qq==n){
		sort(z+1,z+m+1,cmd);
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=1;i<=m;i++){
			int a=find(z[i].u),b=find(z[i].v);
			if(a!=b){
				p[++cnt]={a,b,z[i].w};
				f[a]=b;
				anss+=z[i].w;
			}
			if(cnt==qq-1)break;
		}
		ans=anss;
	}else {
		for(int i=1;i<=cnt;i++)q[i]=p[i];
		sort(q+1,q+cnt+1,cmd);
		int fl=0;
		for(int i=1;i<=qq;i++)f[i]=i;
		for(int i=1;i<=cnt;i++){
			int a=find(q[i].u),b=find(q[i].v);
			if(a!=b){
				anss+=q[i].w;
				f[a]=b;
				fl++;
			}
			if(fl==qq-1)break;
		}
		ans=min(ans,anss);
	}
}
void dfs(int x,long long anss){
	if(x==k+1){
		kruskal(anss,cntt);
		return ;
	}
	dfs(x+1,anss);
	cntt++;
	for(int i=1;i<=n;i++){
		p[++cnt]={cntt,i,t[x][i]};
	}
	dfs(x+1,anss+t[x][0]);
	cnt-=n;
	cntt--;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>z[i].u>>z[i].v>>z[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>t[i][j];
		}
	}
	cntt=n;
	dfs(1,0); 
	cout<<ans;
	return 0;
}

