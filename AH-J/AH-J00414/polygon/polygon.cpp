#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5005],ans;
void dfs(int cnt,int pos,int mx,int sum){
	if(cnt>=3&&sum>mx*2){
		ans=(ans+1)%MOD;
	}for(int i=pos+1;i<=n;i++){
		if(mx<a[i]){
			dfs(cnt+1,i,a[i],sum+a[i]);
		}else{
			dfs(cnt+1,i,mx,sum+a[i]);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
