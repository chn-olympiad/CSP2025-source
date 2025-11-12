#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll Mod=998244353;
const int N=5010;
int n;
array<int,N> a;
ll ans;
ll mod(ll x){
	return (x%Mod+Mod)%Mod;
}
ll qpow(ll x,ll y){
	ll res=1,base=x;
	while(y){
		if(y&1) res=mod(res*base);
		base=mod(base*base);
		y>>=1;
	}
	return res;
}
void R1(){
	sort(a.begin()+1,a.begin()+n+1);
	if(a[3]>a[1]+a[2]) cout<<1;
	else cout<<0;
	exit(0);
}
void dfs(int x,int mx,int sm,int cnt){
	if(x==n+1){
		if(cnt>2&&sm>mx*2) ans=mod(ans+1);
		return;
	}
	dfs(x+1,mx,sm,cnt);
	dfs(x+1,max(mx,a[x]),sm+a[x],cnt+1);
}
void R2(){
	dfs(1,0,0,0);
	cout<<ans;
	exit(0);
}
void R3(){
	ans=mod(qpow(2,n)-mod(n*(n-1)/2+n+1));
	cout<<ans;
	exit(0);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ans=0; 
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=3) R1();
	if(n<=20) R2();
	R3();
	return 0;
}
