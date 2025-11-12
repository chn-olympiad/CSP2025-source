#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=505,mod=998244353;

ll n,a[N],ans;
ll pre[N];

inline void dfs(ll step,ll sum,ll mx){
	
	if(step>n){
		
		if(sum>mx*2) ans=(ans+1)%mod;
		return;
	}
	
	dfs(step+1,sum+a[step],max(mx,a[step]));
	dfs(step+1,sum,mx);
}

inline ll ksm(ll a,ll b){
	
	ll res=1;
	while(b){
		
		if(b&1) res=res*a%mod;
		
		a=a*a%mod;
		b>>=1;
	}
	
	return res;
}

inline ll comb(ll n,ll m){
	
	return pre[n]*ksm(pre[m],mod-2)%mod*ksm(pre[n-m],mod-2)%mod;
}

int main(){
	
	//别忘了最后写 freopen~ 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	bool teshuxingzhi=true;
	
	cin>>n;
	for(int i=1;i<=n;i++){
		
		cin>>a[i];
		
		if(a[i]!=1) teshuxingzhi=false;
	}
	
	if(teshuxingzhi){
		
		pre[0]=pre[1]=1;
		for(int i=2;i<=n;i++) pre[i]=pre[i-1]*i%mod;
		
		for(int i=3;i<=n;i++) ans=(ans+comb(n,i))%mod;
		
		cout<<ans<<'\n';
		return 0;
	}
	
	dfs(1,0,0);
	
	cout<<ans<<'\n';
	
	return 0;
}
//9:43 64pts meaw!
/*

{16} 1,5,2,6,3,7,4,8,
{32} 5,6,7,8,1,2,3,4,
{16} 5/Cf,,,,
{16} 5,1,6,2,7,3,8,4,
{32} 1,2,3,4,5,6,7,8,
{16} 1/Cf,,,,
{16} 1,6,4,5,1,6,4,,
{16} 8,3,5,4,8,3,5,,
{16} 4,4,6,6,3,3,5,5,
{32} 4-8[16:1],3,2,1,8,7,6,5,
{16} 1b,
E

*/
