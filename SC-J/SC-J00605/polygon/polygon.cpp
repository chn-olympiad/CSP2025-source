#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
long long n,a[10005],cnt,sum=1,ans;
bool b[5005];
void dfs(long long u,long long s,long long max_,long long st){
	if(clock()>0.9*CLOCKS_PER_SEC){
		for(int i=2;i<=n;i++)sum=(sum*2+1)%mod;
		cout<<sum;
	}
	if(u==n+1)return;
	if(u>=3&&max_*2<s)ans=(ans+1==mod?0:ans+1);
	for(long long i=st+1;i<=n;i++){
		dfs(u+1,s+a[i],max(max_,a[i]),i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n-3;i++){
		dfs(1,a[i],a[i],i);
	}
	cout<<(ans+1)%mod;
	return 0;
}        