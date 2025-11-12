#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,f[10005],c[15],a[15][10005],ans;
struct edge{
	ll u,v,w;
}ed[10000005];
void init(int n){
	for(int i=1;i<=n;i++)f[i]=i;
}
ll find(ll x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void join(ll x,ll y){
	int a=find(x),b=find(y);
	f[a]=b;
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	init(n);
	for(int i=1;i<=m;i++){
		cin>>ed[i].u>>ed[i].v>>ed[i].w;
	} 
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				ed[++m].u=j;ed[m].v=k;ed[m].w=a[i][j]+a[i][k]+c[i];
			}
		}
	} 
	sort(ed+1,ed+m+1,cmp);
//	for(int i=1;i<=m;i++){
//		cout<<ed[i].u<<" "<<ed[i].v<<" "<<ed[i].w<<"\n";
//	}

	int q=0;
	for(int i=1;i<=m;i++){
		if(find(ed[i].u)!=find(ed[i].v)){
			join(ed[i].u,ed[i].v);
			ans+=ed[i].w;
			q++;
		}
		if(q==n-1)break;
	}
	cout<<ans;
	return 0;
}
/*
4 4 0
1 2 3
2 3 4
3 4 5
1 4 1
*/
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

