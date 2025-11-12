#include<bits/stdc++.h>

using namespace std;
int n,a[5005],ans=0;
void dfs(int idx,int cnt,int sum,int ma){
	if(idx>n){
		if(cnt>=3&&sum>ma*2){
			ans++;
			ans%=998244353;
		}
		return;
	}
	dfs(idx+1,cnt+1,sum+a[idx],max(ma,a[idx]));
	dfs(idx+1,cnt,sum,ma);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,-1);
	cout<<ans;
	return 0;
}
