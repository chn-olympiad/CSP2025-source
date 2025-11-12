#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5005],ans[5005],cnt=0;
ll n;
void dfs(ll cur,ll sum,ll maxn,ll pi){
	if(cur>pi){
		 if(sum>maxn*2){
			  cnt++;
			  cnt%=998244353;
		  }
		 return ;
	 }
	for(ll i=ans[cur-1]+1;i<=n;i++){
		ans[cur]=i;
		dfs(cur+1,sum+a[i],max(maxn,a[i]),pi);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=3;i<=n;i++){
		dfs(1,0,0,i);
	}
	cout<<cnt;
	
	return 0;
}
