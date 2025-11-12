#include<bits/stdc++.h>
using namespace std;
int n,m,k,z[11][10005],f[10005],ans;
struct node{
	int u,v,w;
}a[1000050];
void yzc(int x,int sum,int k){
	if(k==n){
		if(ans!=0) ans=min(sum,ans);
		else ans=sum;
	}
	for(int i=1;i<=m;i++){
		if(a[i].u==x&&f[a[i].v]==0){
			f[a[i].v]=1;
			yzc(a[i].v,sum+a[i].w,k+1);
			f[a[i].v]=0;
		}
		if(a[i].v==x&&f[a[i].u]==0){
			f[a[i].u]=1;
			yzc(a[i].u,sum+a[i].w,k+1);
			f[a[i].u]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(f,0,sizeof(f));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		cin>>z[i][0];
		for(int j=1;j<=n;j++) cin>>z[i][j];
	}
	for(int i=1;i<=n;i++){
		f[i]=1;
		yzc(i,0,1);
		f[i]=0;
	}
	cout<<ans;
	return 0;
}
