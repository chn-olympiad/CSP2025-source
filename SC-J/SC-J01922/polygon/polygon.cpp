#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int ans=0;
void dfs(int idx,int sum,int mx){
	if(idx==n+1){
		if(sum>mx*2){
			ans++;
			ans%=998244353;
		}
		return;
	}else{
		dfs(idx+1,sum+a[idx],a[idx]);
		dfs(idx+1,sum,mx);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	dfs(1,0,0);
	cout<<ans;
	return 0;
} 