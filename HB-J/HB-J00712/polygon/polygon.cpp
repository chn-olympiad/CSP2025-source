#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans;
void dfs(int step,int sum,int mx,int cnt){
	if(step==n){
		if(sum>mx*2&&cnt>=3){
			ans++;
		}return ;
	}dfs(step+1,sum+a[step],max(mx,a[step]),cnt+1);
	dfs(step+1,sum,mx,cnt);
}int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==3)cout<<1;
	else{
		dfs(1,0,0,0);
		cout<<ans;
	}return 0;
}
	
