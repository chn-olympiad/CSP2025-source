#include<bits/stdc++.h>
using namespace std;
int n,k,a[100007],vis[100007];
int dfs(int l,int r){
	if(l==r+1)
		return 0;
	if(vis[l]!=0)
		return vis[l];
	if(a[l]==k){
		vis[l]=1;
		vis[l]=dfs(l+1,r)+1;
		return vis[l];
	}
	if(l!=1&&vis[l-1]==0){
		int temp=a[l];
		a[l]=a[l]^a[l-1];
		if(a[l]==k){
			vis[l]=1;
			vis[l]=dfs(l+1,r)+1;
			return vis[l];
		}
		int o=dfs(l+1,r);
		a[l]=temp;
		vis[l]=max(o,dfs(l+1,r));
		return vis[l];
	}
	vis[l]=dfs(l+1,r);
	return vis[l];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(1,n)<<endl;
	return 0;
}