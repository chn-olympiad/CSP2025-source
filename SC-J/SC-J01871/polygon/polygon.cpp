#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e3+10,mod=998244353;
int n;
int a[N];
int ans;
int mxx;
void dfs(int x,int sum,int mx){
	if(x==n+1){
		ans+=(sum>2*mx);
		ans%=mod;
		return;
	}
	dfs(x+1,sum,mx);
	dfs(x+1,sum+a[x],max(mx,a[x]));
	return;
}
int qpow(int a,int b){
	a%=mod;
	int ans=1;
	while(b>1){
		if(b&1){
			ans*=a;
			ans%=mod;
			a=a*a;
			a%=mod; 
		}else{
			a=a*a;
			a%=mod;
		}
		b>>=1;
	}
	return (a*ans)%mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		mxx=max(mxx,a[i]);
	}
	if(n<=23){
		dfs(1,0,0);
		cout<<ans;
	}else if(mxx==1){
		cout<<(((qpow(2,n)+(mod-n)%mod)%mod+(mod-(n*(n-1)/2))%mod)%mod+(mod-1)%mod)%mod;
	}else{
		cout<<qpow(2,n);
	}
	return 0;
}

//zto 64pts orz

//Total:329pts