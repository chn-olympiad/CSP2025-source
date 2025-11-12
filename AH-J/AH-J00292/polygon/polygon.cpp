#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=6000,mod=998244353;
ll n,a[N],cnt;
bool f[N];
bool check(){
	ll c=0,s=0;
	for(ll i=1;i<=n;i++)if(f[i])c++,s+=a[i];
	if(c<3)return 0;
	for(ll i=1;i<=n;i++)if(f[i])if(a[i]*2>=s)return 0;
	return 1;
}
void dfs(ll c){
	if(c>n){
		if(check())cnt++;
		cnt%=mod;
		return;
	}
	for(ll i=0;i<2;i++){
		if(!i)dfs(c+1);
		else{
			f[c]=1;
			dfs(c+1);
			f[c]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	dfs(1);
	printf("%lld",cnt);
	return 0;
}
