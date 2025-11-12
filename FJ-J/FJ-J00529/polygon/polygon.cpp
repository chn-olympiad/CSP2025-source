#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5005;
const int mod=998244353;
int n;
int ans=0;
int a[maxn];
int cnt=0,sum=0;
int b[maxn];
int fc[maxn];
int inv[maxn];
int qp(int a,int b){
	int pre=1;
	while(b){
		if(b&1) pre=pre*a%mod;
		a=a*a%mod,b/=2;
	}
	return pre;
}
void init(){
	fc[0]=inv[0]=1;
	for(int i=1;i<=5000;i++){
		fc[i]=fc[i-1]*i%mod;
	}
	inv[5000]=qp(fc[5000],mod-2);
	for(int i=4999;i;i--){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
}
int c(int x,int y){
	return fc[x]*inv[y]%mod*inv[x-y];
}
void dfs(int x){
	if(x>n){
		if(sum>b[cnt]*2) ans=(ans+1)%mod;
		return;
	}
	dfs(x+1);
	b[++cnt]=a[x];
	sum+=a[x];
	dfs(x+1);
	cnt--,sum-=a[x];
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1 && a[i]!=a[i-1]) flag=0;
	}
	if(n<3){
		cout<<"0\n";
		return 0;
	}
	if(flag){
		init();
		for(int i=3;i<=n;i++){
			ans=(ans+c(n,i))%mod;
		}
		cout<<ans<<"\n";
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1);
	cout<<ans<<"\n";
	return 0;
}

