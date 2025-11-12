#include<bits/stdc++.h>
using namespace std;
namespace my_space{
	using ll = long long;
	constexpr int N = 5e3+50;
	constexpr int maxn = 1e4+50,mod = 998244353;
	long long cnt[maxn<<4],a[N],ans,tot[N];int n;
	void dfs(ll pos,ll man,ll t,ll sum){
		if(pos==n+1){
			if(t<3) return;
			if(sum>man*2) ans++,ans%=mod;
			return;
		}
		dfs(pos+1,a[pos],t+1,sum+a[pos]);
		dfs(pos+1,man,t,sum);
	}
	ll lowbit(ll x){
		return x&-x;
	}
	void add(ll x,ll st){
		for(ll i=st;i<=maxn;i+=lowbit(i)){
			cnt[i]+=x;
			cnt[i]%=mod;
		} 
	}
	ll query(ll x){
		ll res=0;
		for(ll i=x;i>0;i-=lowbit(i)){
			res+=cnt[i];
			res%=mod;
		}
		return res;
	}
	int main(){
		freopen("polygon.in","r",stdin);
		freopen("polygon.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		if(n>25){
			for(int i=1;i<=n;i++){
			
			//if(i==3) return cout<<query(1e4+1)<<" "<<query(a[i]*2),0;
			ll temp = query(1e4+50)-query(a[i]);
			temp=(temp+mod)%mod;
			
			//cout<<temp<<" "<<query(a[i])<<'\n'; 
			//if(temp<0) return cout<<i<<'\n',0;
			ans+=temp;
			ans=(ans+mod)%mod;
			for(ll j = maxn-a[i];j>=1;j--){
				ll sum = query(j)-query(j-1);
				sum = (sum+mod)%mod; 
				//if(sum<0) return 0;
				add(sum,min(j+a[i],ll(1e4+50))); 
			}
			for(ll j=1;j<i;j++){
				add(1,min(a[i]+a[j],ll(1e4+50)));
			}
		}
		}
		else{
			dfs(1,0,0,0);
		}
		cout<<ans<<'\n';
		return 0;
	}
}
int main(){
	return my_space::main();
}


