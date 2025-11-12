#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
void dfs(int l,int r,int cnt){
	ans=max(ans,cnt);
	if(r>n||l>r){
		return ;
	}int f=a[l];
	for(int i=l+1;i<=r;i++){
		f=(f^a[i]);
	}if(f==k){
		dfs(r+1,r+1,cnt+1);
	}else{
		dfs(l+1,r,cnt);
		dfs(l,r+1,cnt);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}dfs(1,1,0);
	cout<<ans;
	return 0;
}
