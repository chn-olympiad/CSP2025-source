#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+7,K=17,M=1e6+7;
struct node{
	int u,v;
	ll w;
	bool operator<(node x){
		return w<x.w;
	}
}a[M];
struct vil{
	ll w,r[N];
}b[K];
int n,m,k,f[N+K];


int find(int x){
	if(f[x]==x) return f[x];
	return f[x]=find(f[x]);
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	bool fl=0;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		cin>>b[i].w;
		if(b[i].w) fl=1;
		for(int j=1;j<=n;j++){
			cin>>b[i].r[i];
			if(b[i].r[i]) fl=1;
		}
	}
	if(!fl&&k) return cout<<0<<"\n",0;
	else if(k==0){
		ll ans=0;
		sort(a+1,a+m+1);
		for(int i=1;i<=m;i++){
			int u=a[i].u,v=a[i].v;
			u=find(u),v=find(v);
			if(u==v) continue;
			f[u]=v;
			ans+=a[i].w;
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
