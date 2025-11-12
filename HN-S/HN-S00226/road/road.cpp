#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,fa[1005],a[1005][15];
struct node{
	int x,y,w;
	bool operator<(const node &T)const{
		return w<T.w;
	}
}p[1000005];
int Find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=Find(fa[x]);
}
void JO(int x,int y){
	x=Find(x),y=Find(y);
	if(x!=y){
		fa[x]=y;
	}
}
void solve(){
	sort(p+1,p+m+1);
	int ans=0,sum=0;
	for(int i=1;i<=m;i++){
		if(sum==n-1){
			cout<<ans;
			return;
		}
		if(Find(p[i].x)!=Find(p[i].y)){
			JO(p[i].x,p[i].y);
			ans+=p[i].w,sum++;
		}
	}
}
bool check(){
	for(int i=1;i<=n;i++){
		int maxn=0;
		for(int j=0;j<=k;j++){
			maxn=max(maxn,a[i][j]);
		}
		if(!maxn){
			return true;
		}
	}
	return false;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>p[i].x>>p[i].y>>p[i].w;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
		for(int j=0;j<=k;j++){
			cin>>a[i][j];
		}
	}
	if(!k){
		solve();
	}else if(check()){
		cout<<0<<'\n';
	}
	return 0;
}
