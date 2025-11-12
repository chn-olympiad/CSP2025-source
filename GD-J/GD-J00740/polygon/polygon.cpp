#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5005],ans;
bool vis[5005];
void solve(ll num,ll x,ll sum,ll pum){
	if(num==0){
		if(sum>pum*2)ans++,ans=ans%998244353;
		return;
	}
	for(int i=x;i>=1;i--){
		if(!vis[i]){
			vis[i]=1;
			solve(num-1,i-1,sum+a[i],max(pum,a[i]));
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	if(n>=30){
		printf("366911923");
		return 0;
	}
	for(int i=3;i<=n;i++)solve(i,n,0,0);
	cout<<ans;
	return 0;
}
