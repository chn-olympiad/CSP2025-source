#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],ans;
map<pair<long long,pair<long long,long long> >,long long> mp;
bool cond1=1;
long long fpow(long long a,long long b){
	long long ret=1;
	while(b){
		if (b%2){
			ret=(ret*a)%998244353;
			b--;
		}
		else{
			a=(a*a)%998244353;
			b/=2;
		}
	}
	return ret;
}
long long dfs(long long now,long long mx,long long sum,long long cnt){
	if (mp.find(make_pair(now,make_pair(mx,sum)))!=mp.end())
	  return mp[make_pair(now,make_pair(mx,sum))];
	if (now==n){
		if (sum>mx*2&&cnt>=3)
		  return 1;
		return 0;
	}
	if (sum>a[n-1]*2&&cnt>=3){
		mp[make_pair(now,make_pair(mx,sum))]=fpow(2,n-now);
		return mp[make_pair(now,make_pair(mx,sum))];
	}
	long long leave=dfs(now+1,mx,sum,cnt),take=dfs(now+1,a[now],sum+a[now],cnt+1);
	mp[make_pair(now,make_pair(mx,sum))]=(leave+take)%998244353;
	return (leave+take)%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (long long i=0;i<n;i++){
	    cin>>a[i];
	    if (a[i]!=1)
	      cond1=0;
	}
	if (cond1){
		for (long long i=3;i<=n;i++){
			long long multi=1;
			for (long long j=n;j>=n-i+1;j--)
			  multi*=j;
			for (long long j=1;j<=i;j++)
			  multi/=j;
			multi%=998244353;
			ans=(ans+multi)%998244353;
		}
		cout<<ans;
		return 0;
	}
	sort(a,a+n);
	cout<<dfs(0,-1,0,0);
	return 0;
}
