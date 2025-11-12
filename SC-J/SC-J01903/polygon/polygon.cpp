/*xg333 CSP-J must win!!!
T4代码
先弄T3，这题无脑写暴力*/
#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define endl '\n'
const int mod=998244353;
int a[5007];
ll ans=0ll;
int n;
void dfs(int d,int maxn,ll sum,int num){
	if(d==n+1){
		if((sum>(ll)2*maxn)&&(num>2)){
			ans++;
			ans=ans%mod;
		}
		return;
	}
	if((d==n-1&&num==0)||(d==n&&num==1)) return;
	dfs(d+1,max(maxn,a[d]),sum+a[d],num+1);
	dfs(d+1,maxn,sum,num);
}
ll sC(int y){
	ll ans=1;
	for(int i=0;i<y;i++){
		ans*=(n-i);
		ans=ans%mod;
	}
	for(int i=1;i<=y;i++){
		ans=ans/i;
		ans=ans%mod;
	}
	return ans;
}
void solve(){
	cin>>n;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flag=1;
	}
	if(flag==0){
		ll sum=0;
		for(int i=3;i<=n;i++){
			sum=sum+sC(i);
			sum=sum%mod;
		}
		cout<<sum;
	}
	else{
		dfs(1,0,0,0);
		cout<<ans;
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}