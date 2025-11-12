#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=998244353;
int n,a[5005],ans,co,mno;
void dfs(int x,int cnt,int sum,int maxn){
	if(x>n){
		if(cnt>=3&&sum>2*maxn){
			ans=(ans+1)%MOD;
		}
		return ;
	}
	dfs(x+1,cnt+1,sum+a[x],max(maxn,a[x]));
	dfs(x+1,cnt,sum,maxn);
	return ;
}
ll C(ll x,ll y){
	ll ret=1,gax=1;
	for(int i=0;i<x;i++){
		ret=(ret*(y-i))%MOD;
	}
	for(int i=2;i<=x;i++){
		gax=gax*i%MOD;
	}
	return ret/gax;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mno=max(mno,a[i]);
		if(a[i]==1){
			co++;
		} 
	}
	if(mno==1&&n>20){
		for(ll i=3;i<=co;i++){
			ans=(ans+C(i,co))%MOD;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
