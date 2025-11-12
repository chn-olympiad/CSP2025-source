#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,k;
int ans=0;
int yh(int l,int r){
	int yhh=a[l];
	//cout<<l<<r<<endl;
	if(l==r){
		//cout<<yhh<<endl;
		return yhh;
	}
	for(int i=l+1;i<=r;i++){
		yhh=yhh^a[i];
		//cout<<yhh<<endl;
	}
	return yhh;
}
void dfs(int x,int y){
	//cout<<x<<' '<<y<<endl;
	if(x>n){
		//cout<<endl;
		return ;
	}
	if(yh(x,y)==k){
		ans++;
		//cout<<x<<' '<<y;
		dfs(y+1,y+1);
	}
	else{
		if(y<n)dfs(x,y+1);
		else dfs(x+1,x+1);
	}
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1);
	cout<<ans<<endl;
	return 0;
}
//异或和：a^b