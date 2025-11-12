#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
long long ans;
int a[20000];
void dfs(int cnt,int mx,int sum,int now){
	if(now>n){
		if(cnt>=3&&sum>mx*2){
			ans=(ans+1)%mod;
		}
		return;
	}
	dfs(cnt+1,max(mx,a[now]),sum+a[now],now+1);
	dfs(cnt,mx,sum,now+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,1);
	cout<<ans;
	return 0;
}
