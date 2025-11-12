#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
#define ll long long
struct A{ll u,v,w;}a[2*M];
bool cmp(A i,A j){
	return i.w<j.w;
}
ll n,m,k,i,j,u,v,w,c[15],d[N],f[1005][1005],fa[N],fu,fv,s,siz[N];
ll find(ll x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)f[i][j]=1e15;
	for(i=1;i<=n;i++){
		fa[i]=i;
		siz[i]=1;
	}
	for(i=1;i<=m;i++){
		cin>>u>>v>>w;
		if(u>v)swap(u,v);
		if(k)f[u][v]=min(f[u][v],w);
		else{
			a[i].u=u;a[i].v=v;a[i].w=w;
		}
	}
	if(k){
		for(i=1;i<=k;i++){
			cin>>c[i];
			for(j=1;j<=n;j++)cin>>d[j];
			for(u=1;u<n;u++){
				for(v=u+1;v<=n;v++){
					f[u][v]=min(f[u][v],d[u]+d[v]+c[i]);
				}
			}
		}
		m=0;
		for(u=1;u<n;u++){
			for(v=u+1;v<=n;v++){
				if(f[u][v]!=1e15){
					a[++m].u=u;
					a[m].v=v;
					a[m].w=f[u][v];
				}
			}
		}
	}
	sort(a+1,a+1+m,cmp);
	for(i=1;i<=m;i++){
		u=a[i].u;v=a[i].v;w=a[i].w;
		fu=find(u);fv=find(v);
		if(fu!=fv){
			if(siz[u]<siz[v]){
				fa[fu]=fv;
				siz[v]+=siz[u];
			}
			else{
				fa[fv]=fu;
				siz[u]+=siz[v];
			}
			s+=w;
		}
	}
	cout<<s;
}

