#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
int n,m,k;
int fa[maxn];

struct edge{
	int u,v,w;
}a[maxn];

int cmp(edge x,edge y){
	return x.w<y.w;
}

int f(int x){
	if(fa[x]!=x){
		fa[x]=f(fa[x]);
	}
	return x;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		if(f(fa[a[i].u])!=f(fa[a[i].v])){
			ans+=a[i].w;
			if(fa[a[i].v]<fa[a[i].u])fa[f(a[i].v)]=f(a[i].u);
			else fa[f(a[i].u)]=f(a[i].v);
		}
	}
	cout<<ans;
	return 0;
}

