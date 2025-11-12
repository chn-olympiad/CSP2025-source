#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll n,m,k,f[1000005],ans,c;
struct node{
	ll u,v,w;
}a[2000005];
bool cmp(node x,node y){
	return x.w<y.w;
}
ll finds(ll x){
	if(f[x]!=x)f[x]=finds(f[x]);
	return f[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=100025;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(ll j=1,x;j<=n;j++){
			cin>>x;
			a[++m]=node{n+i,j,x};
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(finds(a[i].u)==finds(a[i].v))continue;
		ans+=a[i].w;
		f[a[i].u]=a[i].v;
	}
	cout<<ans;
	return 0;
} 
