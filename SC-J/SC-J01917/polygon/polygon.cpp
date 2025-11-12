#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[1005];
void dfs(int x,int mx,int sum,int cnt,int f){
	if(cnt>=3&&mx*2<sum&&f){
		ans++;
	}
	if(x==n+1)
		return;
	dfs(x+1,max(mx,a[x]),sum+a[x],cnt+1,1);
	dfs(x+1,mx,sum,cnt,0);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<3){
		cout<<0;
		return 0;
	}
	dfs(1,0,0,0,0);
	cout<<ans;
	return 0;
}