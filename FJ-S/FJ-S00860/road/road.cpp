#include<bits/stdc++.h>
#define ll long long 
const int N=1e4+10;
const int M=1e6+10;
const int K=12;
using namespace std;
struct sj{
	int x,y,z;
};
bool operator<(sj x,sj y){
	return x.z<y.z;
}
vector<sj> ver,ver2,ok;
int fa[N+K];
int n,m,k;
int a[K][N];
ll ans,mn;
int getf(int x){
	if(fa[x]==x) return x;
	return fa[x]=getf(fa[x]);
}
void mer(int x,int y){
	x=getf(x);y=getf(y);
	fa[x]=y;
	return ;
}
void fimst(){
	for(int i=1;i<=n+k;i++) fa[i]=i;
	mn=0;
	sort(ver.begin(),ver.end());
	for(int i=0;i<ver.size();i++){
		sj now=ver[i];
		if(getf(now.x)!=getf(now.y)){
			mn+=now.z;
			mer(now.x,now.y);
			ok.push_back(now);
		}
	}
	ans=min(ans,mn);
	return ;
}
void mst(int op){
	for(int i=1;i<=n+k;i++) fa[i]=i;
	ver2=ok;
	mn=0;
	for(int i=0;i<k;i++){
		if((op>>i)&1){
			mn+=a[i+1][0];
			for(int j=1;j<=n;j++) ver2.push_back({n+i+1,j,a[i+1][j]});
		}
	}
	sort(ver2.begin(),ver2.end());
	for(int i=0;i<ver2.size();i++){
		sj now=ver2[i];
		if(getf(now.x)!=getf(now.y)){
			mn+=now.z;
			mer(now.x,now.y);
		}
	}
	ans=min(ans,mn);
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	int x,y,z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		ver.push_back({x,y,z});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++) cin>>a[i][j];
	}
	ans=0x3f3f3f3f3f3f3f3f;
	fimst();
	for(int i=0;i<(1<<k);i++) mst(i);
	cout<<ans<<endl;
	return 0;
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
