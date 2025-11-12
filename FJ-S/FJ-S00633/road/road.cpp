#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,y,z;
}a[1000005];
bool operator <(node x,node y){
	return x.z<y.z;
}

long long fa[100005],t,ans,n,m,k,c[10005][15],f;
long long find(long long x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void kls(){
	for(int i=1;t<n-1;++i){
		if(find(a[i].x)==find(a[i].y))continue;
		fa[a[i].x]=a[i].y;
		++t;
		ans+=a[i].z;
	}
}
void init(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i)cin>>a[i].x>>a[i].y>>a[i].z;
	for(int j=1;j<=k;++j)
	for(int i=0;i<=n;++i)cin>>c[i][j];
}
void print(){
	cout<<ans;
}
void solve(){
	init();
	kls();
	print();
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve(); 
}
