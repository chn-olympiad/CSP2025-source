#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+50,mod=998244353;
int n,ans=0,a[N];
void dfs(int x,int sum,int cnt,int mx){
	if(x==n+1){
		if(sum>mx*2 && cnt>=3) ans++;
		ans%=mod;
		return;
	}
	dfs(x+1,sum+a[x],cnt+1,max(mx,a[x]));
	dfs(x+1,sum,cnt,mx);
}
signed main(){
	freopen("polygon.in","r",stdin);	
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans<<endl;
}