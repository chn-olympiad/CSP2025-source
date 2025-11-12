#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=998244353;
int n,ans;
int a[5005];
void dfs(int x,int s,int mx,int cnt,bool c){
	if(s>mx*2&&cnt>=3&&c)ans++,ans%=mod;
	if(x==n)return ;
	dfs(x+1,s+a[x+1],a[x+1],cnt+1,1);
	dfs(x+1,s,mx,cnt,0);
}
int qpow(int x,int y){
	if(y==1)return x;
	if(y==0)return 1;
	int p=qpow(x,y/2)%mod;
	if(y%2==1)return p*p%mod*x%mod;
	return p*p%mod;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=20)dfs(0,0,0,0,0);
	else{
		ans=qpow(2,n)%mod;
		ans=(ans-n*(n-1)/2-n-1+mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}
//e,60fenbaoli,wojinlile
