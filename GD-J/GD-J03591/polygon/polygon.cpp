#include<iostream>
using namespace std;
const int mod=998244353;
int n,a[5005],ans;
void fun(int idx,int cnt,int sum,int mx){
	if(cnt>=3&&sum>mx*2)
		ans=(ans+1)%mod;
	if(idx>n||cnt+n-idx<3) return ;
	fun(idx+1,cnt,sum,mx);
	fun(idx+1,cnt+1,sum+a[idx],max(mx,a[idx]));
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	fun(1,0,0,0);
	cout<<ans;
	return 0;
}

