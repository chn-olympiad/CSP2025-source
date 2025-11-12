#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,y,z;
}a[1000005];
int n,m,k,vis[100005],vis2[100005],ans,b[11][10005];
bool _(Node x,Node y){
	return x.z<y.z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		int mx=max(a[i].x,a[i].y);
		int mn=min(a[i].x,a[i].y);
		a[i].x=mn;
		a[i].y=mx;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++) cin>>b[i][j];
	}
	sort(a+1,a+n+1,_);
	for(int i=1;i<=n;i++){
		vis[i]=i;
		vis2[i]=1;
	}
	vis[a[1].y]=a[1].x;
	vis[a[1].x]=a[1].x;
	vis2[a[1].x]=2;
	ans+=a[1].z;
	for(int i=2;i<=m;i++){
		int x=a[i].x;
		int y=a[i].y;
		int xx=vis[x];
		while(xx!=vis[xx]){
			xx=vis[xx];
		}
		vis[x]=xx;
		int yy=vis[y];
		while(yy!=vis[yy]){
			yy=vis[yy];
		}
		vis[y]=yy;
		if(xx!=yy){
			vis[y]=vis[x];
			vis2[xx]+=vis2[y];
			vis[y]=vis[x]=xx;
			ans+=a[i].z;
		}
		if(vis[a[1].x]==n) break;
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
