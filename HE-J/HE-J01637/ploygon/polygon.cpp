//深搜+特殊性质 
#define ll long long
#include<bits/stdc++.h>
using namespace std;
const int N=5050;
const ll mod=998244353;
ll a[N];
bool vst[N];
ll ft[N],inft[N];//阶乘,阶乘逆元 
ll qpow(ll a,ll b){//快速幂求逆元 
	ll ans=1;
	while(b){
		if(b&1)ans*=a;
		b>>=1;
		ans%=mod;
		a*=a;
		a%=mod;
	}
	return ans%mod;
}
int n;
ll o;
void dfs(int pos,int cnt,ll sum,ll maxn){//位置用来去重 
	if(pos==n+1){
		if(sum>maxn*2 and cnt>=3){
			o++;
			o%=mod;
		}
		return ;
	}
	for(int i=pos+1;i<=n+1;i++){
		if(!vst[i]){
			vst[i]=1;
			dfs(i,cnt+1,sum+a[i],max(maxn,a[i]));
			vst[i]=0;
		}
	}
	return ;
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)flag=0;
	}
	if(n==3){
		ll maxn=0;
		for(int i=1;i<=3;i++)maxn=max(maxn,a[i]);
		if(a[1]+a[2]+a[3]>2*maxn)cout<<1;
		else cout<<0;
		return 0;
	}
	if(flag){//全是1，答案就是c(3,n)+c(4,n)+c(5,n).......
		//然后还要去求一遍逆元 
		ft[1]=1;
		inft[1]=1;
		inft[0]=1;
		for(int i=2;i<=n;i++){
			ft[i]=ft[i-1]*i;
			ft[i]%=mod;
			inft[i]=qpow(ft[i],mod-2)%mod;//逆元
			//cout<<ft[i]<<" "<<inft[i]<<" "<<ft[i]*inft[i]%mod<<"\n"; 
		}
		ll ans=0;
		for(int i=3;i<=n;i++){
			ans+=(ft[n]*inft[n-i]%mod*inft[i]%mod)%mod;
			ans%=mod;
		}
		cout<<ans%mod;
		return 0;
	}
	dfs(0,0,0,0);
	cout<<o;
	return 0;
}
