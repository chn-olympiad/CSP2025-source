#include<bits/stdc++.h>
using namespace std;
int n,ans,a[505];
void dfs(int h,int maxx,int sum){
	if(h>n){
		if(sum>maxx*2){
			++ans;
		} 
		return;
	}
	dfs(h+1,max(maxx,a[h]),sum+a[h]);
	dfs(h+1,maxx,sum);
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygan.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,-1,0);
	cout<<ans-1;
	return 0;
} 
