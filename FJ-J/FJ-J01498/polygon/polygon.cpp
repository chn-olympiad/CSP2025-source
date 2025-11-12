#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int fac[5050],inv[5050];
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res*=a,res%=mod;
		a*=a;
		a%=mod;
		b>>=1;
	} 
	return res;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i;
	for(int i=1;i<=n;i++)inv[i]=qmi(fac[i],mod-2);
//	for(int i=1;i<=n;i++)cout<<fac[i]<<" "<<inv[i]<<"\n"; 
} 
int c(int n,int m){
	if(m>n)return 0;
	if(n==m)return 1;
	return (((fac[n]*inv[m])%mod)*inv[n-m])%mod;
}
vector<int> sum;
vector<int> a;
int tmp=0;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	int n;
	cin>>n;
	init(n);
	sum.resize(n+2);
	a.resize(n+2);
	int cnt1=0,cnt0=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];if(a[i]==1)cnt1++;else if(!a[i])cnt0++;
	}
	if(cnt1+cnt0==n)
		cout<<(c(cnt1,3)*qmi(2,cnt0))%mod<<"\n";
	else {
		sort(a.begin()+1,a.end()-1);
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
		}
		int ans=0;
		for(int i=3;i<=n;i++){
			if(sum[i]<=a[i]*2)continue;
			for(int j=3;j<=i;j++){
				int more=sum[i]-sum[i-j]-(a[i]*2+1);
//				cout<<" "<<more<<"\n";
				if(more==0)ans++,ans%=mod;
				if(more>0){
					int low=lower_bound(a.begin()+1,a.end()-1,a[i-j+1]-more)-a.begin();
//					cout<<i<<' '<<j<<" "<<low<<"\n";
					if(low>i-j+1)continue;
					else {
						for(int k=i-low;k>=j-1;k--){
							ans+=c(k,j-1)*2/3;
							ans%=mod;
						}
					}
					if(j==n)ans++,ans%=mod;
				}
//				cout<<ans<<"a\n";
			}
			
		}
		cout<<ans<<"\n";
	}
}
//资瓷CCF评测机能赢!!! 
//跑过3e8!!! 

