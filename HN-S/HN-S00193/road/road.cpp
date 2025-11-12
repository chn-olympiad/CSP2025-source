#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=1e4+5,K=15;
int n,m,k;
struct Node{
	int u,v,w;
}p[N];
int c[N],a[K][M];
bool cmp(Node x,Nodey){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(a+1,a+n+1,cmp);
	int ans;
	for(int i=1;i<=m-1;i++){
		ans+=a[i].w;
	}
	cout<<ans;
	return 0;
}
