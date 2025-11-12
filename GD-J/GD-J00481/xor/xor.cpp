#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,k,maxx;
void dfs(int l,int r,int sum){
	if(l>n){
		maxx=max(maxx,sum);
		return;
	}
	if(r>n){
		return;
	}
	if(l>r){
		return;	
	}
	int now=a[l];
	for(int i=l+1;i<=r;i++){
		now^=a[i];
	}
	if(now!=k){
		dfs(l+1,r,sum);
		dfs(l,r+1,sum);
	}else{
		dfs(r+1,r+1,sum+1);
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1,0);
	cout<<maxx;
	return 0;
}
