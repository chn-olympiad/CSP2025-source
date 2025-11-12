#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,i,T,a[5010];
long long dfs(long long s,long long k,long long m){
	s+=a[m];k=max(k,a[m]);
	long long t=s>(k<<1)?1:0;
	for(int i=m+1;i<=n;i++)
	t=(t+dfs(s,k,i))%mod;
	return t;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=n;i++)
	T=(T+dfs(0,0,i))%mod;
	cout<<T;
	return 0;
}
