#include<bits/stdc++.h>
using namespace std;
int n,a[1007],vis[1007],ans;
void dfs(int l,int r,int k){
	if(vis[l]!=0)
		return;
	if(!k){
		int xz[1007]={},t=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==1){
				xz[++t]=a[j];
			}
		}
		int maxx=-1,sum=0;
		for(int i=1;i<=t;i++){
			maxx=max(maxx,xz[i]);
			sum+=xz[i];
		}
		if(sum>2*maxx)
			ans++;
		return;
	}
	if(l>r)
		return; 
	vis[l]=1;
	dfs(l+1,r,k-1);
	vis[l]=0;
	dfs(l+1,r,k);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int j=3;j<=n;j++)
		dfs(1,n,j);
	cout<<ans<<endl;
	return 0;
}