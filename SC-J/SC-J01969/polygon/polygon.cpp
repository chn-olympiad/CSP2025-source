#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5001],dp[5001][5001],mod=998244353;
bool flag=false;
long long way(long long step,long long maxx,long long tot,long long num){
	if(step>n&&num>=3){
		if(tot>maxx*2) return 1;
		else return 0;
	}
	else if(step>n) return 0;
	return (way(step+1,a[step],tot+a[step],num+1)%mod+way(step+1,maxx,tot,num)%mod)%mod;
}
long long com(long long k){
	long long a=1,b=1;
	k=min(n-k,k);
	for(int i=1;i<=k;i++){
		a*=k;
		b*=(n-i+1);
	}
	return b/a;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flag=true;
	} 
	sort(a+1,a+1+n);
	if(n<=20)cout<<way(1,0,0,0);
	else if(!flag){
		long long tot=0;
		for(int i=3;i<=n;i++){
			tot+=com(i);
		}
	} 
	return 0;
} 