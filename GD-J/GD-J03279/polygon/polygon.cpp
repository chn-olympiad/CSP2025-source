#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
const ll mod=998244353;
ll n;
ll A[N];
ll ans,cnt;
void dfs(ll x,ll y,ll sum,ll maxs,bool flag){
	cnt++;
	if(y>=3&&sum>maxs*2ll&&flag)
		ans=(ans+1)%mod;
	if(x>n)
		return;
	if(cnt>1e9)
		return;
	dfs(x+1,y,sum,maxs,0);
	dfs(x+1,y+1,sum+A[x],max(maxs,A[x]),1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;	
	for(int i=1;i<=n;i++)
		cin>>A[i];
	dfs(1,0,0,-1,0);
	cout<<ans<<endl;
	return 0;
}
