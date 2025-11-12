#include<bits/stdc++.h>
using namespace std;
long long n,m,k,fa[10010],ans,a[11][10010],cnt,aans=1e9,bian,sum;
struct kk{
	long long to,start,w;
}e[1000010];
bool cmp(kk x,kk y){
	return x.w<y.w;
}
int find(int u){
	if(fa[u]==u)return u;
	fa[u]=find(fa[u]);
	return fa[u];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].start>>e[i].to>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>a[i][0];
		ans=0;
		for(int j=1;j<=n;j++)cin>>a[i][j],ans+=a[i][j],fa[j]=j;
		ans+=a[i][0];
		aans=min(aans,ans);
	}
	sort(e+1,e+1+m,cmp);
	while(bian<n-1){
		cnt++;
		int u=e[cnt].start,v=e[cnt].to;
		u=find(u);
		v=find(v);
		if(u!=v){
			sum+=e[cnt].w;
			fa[u]=v;
			bian++;
		}
	}
	cout<<min(sum,aans);
	
	return 0;
} 
