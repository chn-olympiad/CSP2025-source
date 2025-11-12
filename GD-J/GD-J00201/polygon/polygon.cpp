#include <bits/stdc++.h>
using namespace std;
long long MOD=998244353;
int a[5005],n,maxn=0,sum=0;
void solve(){
	long long ans=1+n,ji=n*(n-1);
	for(int i=n-2;i>=3;i--){
		ans+=ji;
		ans%=MOD;
		ji*=i;
		ji%=MOD;
	}
	cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool flag=true;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=false;
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	if(n==3){
		if(sum>2*maxn){
			cout<<1;
			return 0;
		}
	}
	if(flag){
		solve();
	}
	return 0;
} 
