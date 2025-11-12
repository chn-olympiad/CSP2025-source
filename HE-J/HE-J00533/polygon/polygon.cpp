#include<bits/stdc++.h>
using namespace std;
int n,a[5100],num;
void dfs(int x,int sum,int ans){
	if(x==n){
		if(sum>ans*2) num++;
		return;
	}
	dfs(x+1,sum+a[x+1],max(ans,a[x+1]));
	dfs(x+1,sum,ans);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    dfs(0,0,0);
    cout<<num;
	return 0;
}
