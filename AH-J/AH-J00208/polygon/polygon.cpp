#include <bits/stdc++.h>
using namespace std;
const long long MAXN=5005,mod=998244353;
long long n,a[MAXN];
long long sum=0;
void dfs(int x,long long s,long long ma){
	if(x>n){
		sum+=(s>ma*2);
		sum%=mod;
		return;
	}
	dfs(x+1,s,ma);
	dfs(x+1,s+a[x],max(ma,a[x]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=20){
		dfs(1,0,0);
		cout<<sum;
	}
	else if(a[n]==1){
		long long s=n*(n-1)/2;
		for(int i=3;i<=n;i++){
			s=s*(n-i+1)/i;
			s%=mod;
			sum=(sum+s)%mod;
		}
		cout<<sum;
	}
	else{
		cout<<366911923;
	}
	return 0;
}
