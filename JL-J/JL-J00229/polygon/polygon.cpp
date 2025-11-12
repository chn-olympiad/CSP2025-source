#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5010,mod=998244353;
int n,a[N],res=0;
void dfs(int idx,int cnt,int sum,int maxi){
	if(idx==n+1){
		if(cnt>=3&&sum>maxi*2)res++;
		return;
	}
	dfs(idx+1,cnt+1,sum+a[idx],max(maxi,a[idx]));
	dfs(idx+1,cnt,sum,maxi);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0,0);
	cout<<res%mod;
	return 0;
}
