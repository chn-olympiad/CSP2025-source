#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=5e5+10;
ll n,k;
ll a[N],vis[N];
unordered_map<int,int> mp;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		
	}
	
	for(int i=1;i<=n;i++){
		vis[i]=vis[i-1]^a[i];
	}
	
	mp[k]=1;
	ll last=0,ret=0;
	for(int i=1;i<=n;i++){
		ll val=vis[i]^vis[last];
		if(mp[val]){
			mp.clear();
			mp[k]=1;
			ret++;
			last=i;
		}	
		else{
			mp[val^k]=1;
		}
	}
	printf("%lld\n",ret);
	
	return 0;
}
