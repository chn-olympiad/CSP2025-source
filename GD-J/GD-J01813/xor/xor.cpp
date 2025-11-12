#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,k,a[N];
map<ll,bool> mp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	ll l=1,sum=0,ans=0;
	mp[l][0]=1;
	for(int i=1;i<=n;i++){
		sum=(sum^a[i]);
		if(mp[l][(sum^k)]){
			ans++;
			sum=0;
			l++;
			mp[l][0]=1;
		}else{
			mp[l][sum]=1;
		}
	}
	printf("%lld",ans);
	return 0;
} 
