#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5005;
int n;
ll mod=998244353;
ll a[maxn];
ll ans;
ll f[maxn];
ll c(int x){
	ll sum=1;
	for(int i=1;i<=x;i++){
		sum*=i;
	}
	return sum%mod;
}
int t;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) t=1;
	}
	if(!t){
		for(int i=3;i<=n;i++){
			ll cnt=c(i);
			ans+=cnt;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	do{
		priority_queue<int> q;
		int sum=0;
		q.push(a[1]);
		q.push(a[2]);
		sum+=(a[1]+a[2]);
		for(int i=3;i<=n;i++){
			q.push(a[i]);
			sum+=a[i];
			int mx=q.top();
			if(sum>2*mx){
				f[i]++;
				f[i]%=mod;
			}
		}
	}while(next_permutation(a+1,a+n+1));
	for(int i=3;i<=n;i++){
		ll cnt=(f[i]/(c(i)*c(n-i)))%mod;
		ans+=cnt;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}