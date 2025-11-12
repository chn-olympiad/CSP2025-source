#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct node{
	int u,v,w;
}a[N];
int n,m,k,c[15][N],d,vis[N],ans;
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++)
			cin>>c[i][j];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++)
		ans+=a[i].w;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
