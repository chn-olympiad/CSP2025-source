#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,mod=998244353;
int n,a[N],ans;
deque<int> v;
inline void dfs(int k){
	if(k==n){
		int sum=0,mx=0;
		deque<int> p=v;
		if(p.size()<3) return ;
		while(!p.empty()){
			int x=p.front();
			p.pop_front();
//			cout<<x<<" ";
			sum+=x;
			mx=max(mx,x);
		}
		if(sum>mx+mx){
			ans=(ans+1)%mod;
		}
//		cout<<ans<<"\n";
		return ;
	}
	dfs(k+1);
	v.push_back(a[k+1]);
	dfs(k+1);
	v.pop_back();
}
inline bool all(){
	for(register int i=1;i<=n;++i){
		if(a[i]!=1) return false;
	}
	return true;
}
int c[5005][5005];
void init(){
	for(register int i=1;i<=5000;++i){
		c[i][0]=1;
		c[i][1]=i;
		for(register int j=2;j<=i;++j){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(register int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(all()){
		init();
		for(register int i=3;i<=n;++i){
			ans=(ans+c[n][i])%mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(0);
	cout<<ans;
	return 0;
}
