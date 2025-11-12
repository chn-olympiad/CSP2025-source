#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll a[5005],cnt=0,b[5005];
ll n;
void dfs(ll cur,ll m,ll sum,ll maxn){
	if(cur>n) return ;
	if(m>=3){
		if(sum>maxn*2){
			cnt%=mod;
			cnt++;
		}
	}
	for(int i=cur+1;i<=n;i++){
		dfs(i,m+1,sum+a[i],max(maxn,a[i]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) dfs(i,1,a[i],a[i]);
	cout<<cnt%mod;
	return 0;
}
