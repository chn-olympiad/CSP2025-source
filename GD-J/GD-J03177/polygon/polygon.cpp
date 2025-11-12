#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0;
void dfs(int x,int mx,int sum,int cnt){
	if(x>n){
		if(sum>mx*2 && cnt>=3){
			ans++;
			ans=ans%244;
		}
		return;
	}
	dfs(x+1,max(mx,a[x]),sum+a[x],cnt+1);
	dfs(x+1,mx,sum,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
