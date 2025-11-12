#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e3;
const int mod=998244353;
int n,a[N],fact[N],inv[N],finv[N],sum[N];
int ans;
bool cmp(int x,int y){
	return x>y; 
}
int C(int n,int m){
	return fact[n]*finv[m]%mod*finv[n-m]%mod;	
}
int solve(int maxx,int l,int r,int len){
	int ll=l,rr=r;
	int cnt;
	while(l<=r){
		int mid=(l+r)/2;
		if(mid-len+1<ll){
			l=mid+1;
			continue;
		}
		if(sum[mid]-sum[mid-len]>maxx){
			cnt=mid;
			l=mid+1;
		}		
		else r=mid-1;
	}
	return cnt;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	bool flag=true;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)	flag=false;	
	}
	
	finv[0]=1;
	fact[1]=inv[1]=finv[1]=1;
	for (int i=2;i<=n;i++){
		fact[i]=fact[i-1]*i%mod;
		int k=mod/i,j=mod%i;
		inv[i]=(-(inv[j]*k)%mod+10*mod)%mod;
		finv[i]=(finv[i-1]*inv[i])%mod;
	}
	sort(a+1,a+n+1,cmp);
	
	for (int i=1;i<=n;i++)	sum[i]=(sum[i-1]+a[i])%mod;
	
	if(flag){
		for (int i=3;i<=n;i++)
			ans=(ans+C(n,i))%mod;
		
		cout <<ans<<endl;	
	}
	else{
		for (int i=1;i<=n;i++){
			for (int j=2;j<=n-i;j++){
				int k=solve(a[i],i+1,n,j);
				ans=(ans+C(k-i,j))%mod;
			}
		}
		cout <<ans;
	}
}
