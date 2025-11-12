#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,a[11][10001],fa[10020],cnt,c[11];
int find(int x){return fa[x]==x?x:find(fa[x]);}
struct node{
	int u,v,w;
}t[1000001],f[1000001];
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>t[i].u>>t[i].v>>t[i].w;
	sort(t+1,t+1+m,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	ll sum=0;
	for(int i=1;i<=m;i++){
		int fu=find(t[i].u),fv=find(t[i].v);
		if(fu==fv)continue;
		sum+=t[i].w,fa[fu]=fv;
		t[++cnt]={t[i].u,t[i].v,t[i].w};
	}
	ll ans=sum;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	for(int S=1;S<(1<<k);S++){
		ll s=0;
		cnt=n-1;
		for(int i=1;i<=cnt;i++)f[i]=t[i];
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1;i<=k;i++)
			if(S&(1<<(i-1))){
				s+=c[i];
				for(int j=1;j<=n;j++)f[++cnt]={i+n,j,a[i][j]};
			}
		sort(f+1,f+1+cnt,cmp);
		for(int i=1;i<=cnt;i++){
			int fu=find(f[i].u),fv=find(f[i].v);
			if(fu==fv)continue;
			s+=f[i].w,fa[fu]=fv;
		}
		ans=min(ans,s);
	}
	cout<<ans<<'\n';
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