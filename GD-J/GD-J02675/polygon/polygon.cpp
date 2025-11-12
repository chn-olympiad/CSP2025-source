#include<bits/stdc++.h>
const long long N=5004;
const long long MOD=998244353;
bool flag=0;
long long a[N];
long long ans=0;
long long n;
std::vector<long long> v;
void dfs(long long sum,long long now){
	if(now==n+1){
		long long mx=-1e9;
		for(auto &x:v) mx=std::max(mx,x);
		if(sum>mx*2&&v.size()>=3){
			ans++;
			ans%=MOD;
		}
		return ;
	}
	dfs(sum,now+1);
	v.push_back(a[now]);
	dfs(sum+a[now],now+1);
	v.pop_back();
} 
long long C(long long m,long long n){
	long long jie=1;
	for(long long i=n;i>m;i--){
		jie*=i;
		jie%=MOD;
	}
	long long jie1=1;
	for(long long i=m;i>=1;i--){
		jie1*=i;
		jie1%=MOD;
	}
	return jie/jie1;
}
void solve(){
	std::cin>>n;
	for(long long i=1;i<=n;i++){
		std::cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	std::sort(a+1,a+n+1,std::greater<long long>());
	if(!flag){
		for(long long i=3;i<=n;i++){
			ans+=C(i,n);
			ans%=MOD;
		}
		std::cout<<ans;
		return ;
	}	
	dfs(0,1);
	std::cout<<ans;
	return ;
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
