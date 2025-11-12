#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+10;
map < ll,ll > mp;
map < ll,ll > mp2;
ll l[N],dp[N],a[N],p[N],n,k;
inline ll read(){
	ll x=0,f=1;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f = -1;
		ch = getchar();
	}
	while('0'<=ch&&ch<='9'){
		x = x*10+ch-'0';
		ch = getchar();
	}
	return x*f;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		a[i] = read();
	}
	p[0] = 0;
	for(ll i=1;i<=n;i++){
		p[i] = p[i-1]^a[i];
//		cout<<p[i]<<" ";
	}
//	cout<<endl;
	mp[0] = 0;
	mp2[0] = 1;
	for(ll i=1;i<=n;i++){
		ll tmp = k^p[i];
//		cout<<tmp<<" "<<p[i]<<" "<<k<<endl;
		if(mp2[tmp]==1){
			l[i] = mp[tmp]+1;
		}
		else {
			l[i] = -1;
		}
		mp2[p[i]] = 1;
		mp[p[i]] = i;
	}
//	for(ll i=1;i<=n;i++){
//		cout<<l[i]<<" ";
//	}
	for(ll i=1;i<=n;i++){
		if(l[i]==-1){
			dp[i] = dp[i-1];
		}
		else{
			dp[i] = max(dp[i-1],dp[l[i]-1]+1);
		}
	}
	cout<<dp[n];
	return 0;
}
/*
4 3
2 1 0 3

4 2
2 1 0 3

4 0
2 1 0 3
*/
