#include<bits/stdc++.h>
const int N=5005;
const int MOD=998244353;
#define ll long long
int ans=0;
int n;
ll f[N];
ll a[N];
std::map<std::vector<int>,int> mp;
void dfs(int now,ll cnt,ll max,int num,std::vector<int> vis){
	if(cnt>max*2 and num>=3 and mp[vis]==0){
	ans++;
	ans%=MOD;
	mp[vis]=1;
	}
	if(now>n)return ;
	dfs(now+1,cnt,max,num,vis);
	vis.push_back(now);
	dfs(now+1,(cnt+a[now])%MOD,std::max(max,a[now]),num+1,vis);
}
ll qpow(ll n,int p){
	if(p==0)return 1;
	if(p==1)return n;
	ll res=1;
	while(p){
		if(p%2)res=(res*n)%MOD;
		res=(res*n)%MOD;
	}
	return res;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	std::cin>>n;
	bool flag=true;
	for(int i=1;i<=n;i++){
	std::cin>>a[i];
	if(a[i]>1)flag=false;
	}
	if(!flag){
	std::vector<int> v;
	dfs(1,0,-1,0,v);
	std::cout<<ans%MOD;
	}
	else {
		f[0]=1;
		for(int i=1;i<=n;i++){
			f[i]=(f[i-1]*i) %MOD;
		}
//		for(int i=1;i<=n;i++)std::cout<<f[i]<<" ";
		ll res=0;
		for(ll i=3;i<=n;i++){
			ll now=f[n]/f[n-i]/f[i];
			now%=MOD;
			res+=now;
		}
		std::cout<<res;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
