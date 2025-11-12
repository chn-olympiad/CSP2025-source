#include<bits/stdc++.h>
#define ff(i,n) for(int i=1;i<=n;i++) 
#define int long long
using namespace std;
const int N=2e5+10,M=2e6,mod=998244353; 
int i,j,k,n,m,x,y,tot;
int cnt[N],sum[N],a[N];
void Add(int val){
	for(int i=10000;i>=0;i--){
		if(i+val<=10000)cnt[i+val]+=cnt[i];
	}
	for(int i=1;i<=10000;i++){
		cnt[i]%=mod;
		sum[i]=(sum[i-1]+cnt[i])%mod;
	}
} 
main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	ff(i,n){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	int s=1,ans=0;
	cnt[0]=1;
	ff(i,n){
		if(i>=3)ans=(ans+(s-1-sum[a[i]]+mod)%mod)%mod;
//		cout<<(s-1-sum[a[i]]+mod)%mod<<'\n';
		s=s*2%mod;
		Add(a[i]);
	}
	cout<<ans;
}
