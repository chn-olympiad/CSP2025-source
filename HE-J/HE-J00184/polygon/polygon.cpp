#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+666;
const int mod=998244353;
int a[N],inv[N],n,ans,fac[N];
bool flag=1;
int Quick_pow(int x,int y){
	int sum=1;
	while(y){
		if(y&1)sum=(sum*x)%mod;
		x=x*x%mod;
		y>>=1;
	}
	return sum;
}
void work_out(){
	fac[0]=1,fac[1]=1;
	for(int i=2;i<=5000;i++){
		fac[i]=fac[i-1]*i%mod;
//		cout<<fac[i]<<" ";
	}
	for(int i=0;i<=5000;i++){
		inv[i]=Quick_pow(fac[i],mod-2);
//		cout<<inv[i]<<"\n";
	}
}
int solve(int n,int k){
	return ((fac[n]*inv[k])%mod)*inv[n-k]%mod;
}
void dfs(int sum,int cnt,int k,int maxn){
	if(k<maxn){
		if(cnt>=2&&sum+a[maxn]>2*a[maxn]){
		//cout<<maxn<<" "<<k<<"\n";
			ans++;
		}
		dfs(sum+a[k],cnt+1,k+1,maxn);
		dfs(sum,cnt,k+1,maxn);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}
	sort(a+1,a+1+n);
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		if(a[1]+a[2]<=a[3])cout<<0;
		else cout<<1;
		return 0;
	}
	else if(flag){
		work_out();
		for(int i=3;i<=n;i++){
			ans=(ans+solve(n,i))%mod;
		}
		cout<<ans;
		return 0;
	}
	else{
		for(int i=3;i<=n;i++){
			dfs(0,0,1,i);
		}
		cout<<ans;
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
