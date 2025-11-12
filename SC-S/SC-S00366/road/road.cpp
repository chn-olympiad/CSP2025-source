#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=3e6+10;
struct tu{
	int u,v,w;
}g[N];
int f[N];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void join(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy) f[fx]=fy;
	return ;
}
bool cmp(tu a,tu b){
	return a.w<b.w;
}
int n,m,k;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int sum=0;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>g[i].u>>g[i].v>>g[i].w;
	}
	if(k==0){
		sort(g+1,g+m+1,cmp);
		for(int i=1;i<=m;i++)
			if(find(g[i].u)!=find(g[i].v)) sum+=g[i].w,join(g[i].u,g[i].v);
		cout<<sum;
	}
	else{
		for(int i=1;i<=k;i++){
			int o;
			cin>>o;
			for(int j=1;j<=n;j++) cin>>o,g[n+j].u=n+i,g[n+j].v=j,g[n+j].w=o,m++;
		}
		n+=k;
		sort(g+1,g+m+1,cmp);
		for(int i=1;i<=m;i++)
			if(find(g[i].u)!=find(g[i].v)) sum+=g[i].w,join(g[i].u,g[i].v);
		cout<<sum;
	}
	return 0;
}