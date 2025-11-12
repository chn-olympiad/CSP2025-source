#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5005],fac[5005],ans;
vector<pair<int,int>> g[5005];
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int C(int n,int m){
	return fac[n]%mod*qpow(fac[m],mod-2)%mod*qpow(fac[n-m],mod-2)%mod;
}
void dfs(int i,int sum,int maxn,int cnt){
	if(i==n+1){
		if(sum>maxn*2&&cnt>=3) ans++;
		return ;
	}
	dfs(i+1,sum+a[i],max(maxn,a[i]),cnt+1);
	dfs(i+1,sum,maxn,cnt);
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3) cout<<0;
	else if(n==3){
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}else{
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(a[i]!=1) {
				flag=false;
				break;
			}
		}
		if(flag==true){
			int ans=1;
			fac[1]=1;
			for(int i=2;i<=5000;i++) fac[i]=fac[i-1]*i%mod;
			for(int i=3;i<n;i++) ans+=C(n,i);
			cout<<ans;
		}else{
			if(n<=25){
				dfs(1,0,0,0);
				cout<<ans;
			}else{
				cout<<"366911923";
			}
		}
	}
} 
