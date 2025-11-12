#include<bits/stdc++.h>
using namespace std;
long long n,m,c[10010],a[11][10010],k,fa[10010];
long long ans=0;
struct node{
	long long u,v,w;
}p[1100010];
bool cmp(node x,node y){
	return x.w<y.w;
}
long long find(long long x){
	return (x==fa[x])?x:(fa[x]=find(fa[x]));
}
void solve(){
	sort(p+1,p+m+1,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		if(find(p[i].u)!=find(p[i].v)){
			fa[find(p[i].u)]=find(p[i].v);
			ans+=p[i].w;
		}
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>p[i].u>>p[i].v>>p[i].w;
	}
	bool flag=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)flag=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		solve();
	}
	else if(flag){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					m++;
					p[m].u=i;
					p[m].v=j;
					p[m].w=a[i][j];
				}
			}
		}
		solve();
	}
	else cout<<0<<endl;
	return 0;
}
