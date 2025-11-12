#include<bits/stdc++.h>
#define ll long long
#define N 1000001
using namespace std;
ll ak,n,m,k,fa[N],ans,c[N],op[100000];
int b[10001][10001],d[N];
struct node{
	ll u,v,w;
}a[N];
bool comp(node x,node y){
	return x.w<y.w;
}
ll fi(ll x){
	while(x!=fa[x])x=fa[x];
	return x;
}
void lian(ll x,ll y){
	fa[fi(x)]=fi(y);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0),cout.tie(0);
cin>>n>>m>>k;
for(int i=1;i<=m;i++){
	cin>>a[i].u>>a[i].v>>a[i].w;
}
if(k==0){
	sort(a+1,a+1+m,comp);
	
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		if(fi(a[i].u)!=fi(a[i].v)){
			ans+=a[i].w;
			lian(a[i].u,a[i].v);
		}
	}
	cout<<ans;
	return 0;
}
for(int i=1;i<=k;i++){
	cin>>c[i];
	for(int j=1;j<=n;j++){
		cin>>d[j];
		if(d[j]==0)op[i]=j;
	}
	for(int j=1;j<=n;j++){
		if(b[op[i]][j]!=0)b[op[i]][j]=min(b[op[i]][j],d[j]);
		else b[op[i]][j]=d[j];
	}
}
for(int i=1;i<=k;i++){
	for(int j=1;j<=n;j++){
		a[++m].w=b[op[i]][j],a[m].u=op[i],a[m].v=j;
	//	cout<<b[op[i]][j];
	}
}
sort(a+1,a+1+m,comp);
for(int i=1;i<=n;i++)fa[i]=i;

	for(int i=1;i<=m;i++){
		if(fi(a[i].u)!=fi(a[i].v)){
			ans+=a[i].w;
			lian(a[i].u,a[i].v);
			ak++;
		}
		if(ak==n-1)break;
	}
	cout<<ans;
	return 0;
} 


