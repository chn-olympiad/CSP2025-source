#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+7;
ll n,k,arr[N],cnt;
vector<pair<ll,ll> >b;
map<ll,ll>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	mp[k]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
		arr[i]^=arr[i-1];
		if(mp[arr[i]]||arr[i]==k){
			b.emplace_back(make_pair(i,mp[arr[i]]+1));
		}
		mp[arr[i]^k]=i;
	}
	sort(b.begin(),b.end());
	ll pre=0,len=b.size();
	for(int i=0;i<len;i++){
		pair<ll,ll>x=b[i];
		if(x.second>pre){
			pre=x.first;
			cnt++;
		}
	}
	printf("%lld",cnt);
	return 0;
} 
