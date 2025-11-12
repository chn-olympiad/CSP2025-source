#include<bits/stdc++.h>
#define rd read()
#define el putchar('\n')
using namespace std;
typedef long long ll;

ll read(){
	char ch=getchar();
	ll x=0,flag=1;
	while(!isdigit(ch)){
		if(ch=='-'){
			flag=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*flag;
}
void write(ll x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x<10){
		putchar(x+'0');
	}else{
		write(x/10);
		putchar(x%10+'0');
	}
}

const ll MAXN=5e3+5,inf=1e18,mod=998244353;
ll n,ans;
ll a[MAXN];
void dfs(ll now,ll cnt,ll sum,ll maxn){
	if(cnt>=3&&now==n+1&&maxn<sum-maxn){
		ans++;
		return ;
	}
	if(now==n+1){
		return ;
	}
	dfs(now+1,cnt,sum,maxn);
	dfs(now+1,cnt+1,sum+a[now],a[now]);
}
void solve10(){
	dfs(1,0,0,0);
	write(ans);
}
ll f[MAXN];
ll C(ll n,ll m){
	return f[n]/(f[m]*f[n-m])%mod;
}
void solveA(){
	f[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]*i%mod;
	}
	for(ll i=3;i<=n;i++){
		ll m=min(i,n-i);
		ll x=C(n,m);
		cout<<x<<"\n";
		ans=(ans+x)%mod;
	}
	write(ans);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=rd;
	ll A=0;
	for(int i=1;i<=n;i++){
		a[i]=rd;
		A=max(A,a[i]);
	}
	sort(a+1,a+n+1);
	if(n<=3){
		write(0);
		return 0;
	}
	if(n<=20){
		solve10();
		return 0;
	}
	if(A==1){
		solveA();
		return 0;
	}
	return 0;
}
