#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll Mod=998244353;
ll n,ans;
int a[5005];
bool cmp(int a,int b){
	return a<b;
}
void dfs(ll num,int s){
	if(num+a[s]>2*a[s] && a[s]!=0){
		ans++;
		ans%=Mod;
	} 
	if(s>=n) return ;
	dfs(num+a[s],s+1);
	dfs(num,s+1);
	return ;
}
ll C1(int a){
	if(a>n/2) a=n-a;
	ll x=1,y=1;
	for(int i=0;i<a;++i){
		x*=n-i,y*=i+1;
		x%=Mod,y%=Mod;
	}
	return x/y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(a[n]==1){
		ans=1;
		for(int i=3;i<n;++i){
			ans+=C1(i);
			ans%=Mod;
		}
		cout<<ans%Mod;
		return 0;
	}
	dfs(0,1);
	cout<<ans%Mod;
	return 0;
}

