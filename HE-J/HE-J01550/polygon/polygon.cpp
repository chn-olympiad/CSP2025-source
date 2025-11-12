#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int N=5e3+10,mod=998244353;
int dp2[N],dp3[N],jc[N],a[N],s[N];
int sum;
int ksm(int x,int y,int mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ans%mod*x%mod)%mod;
		x=(x%mod*x%mod)%mod;
		y=y>>1;
	}
	return ans;
}
void dfs(int x,int su){
	if(x==n) return;
	su+=a[x];
	if(x>=2) for(int i=x+1;i<=n;i++) if(su>a[i]) sum++,sum%=mod;
	
	dfs(x+1,su);
	su-=a[x];
//	if(x>=2)for(int i=x+1;i<=n;i++) if(su>a[i]) cout<<x<<' '<<i<<' '<<su+a[i]<<endl,sum++;
	
	dfs(x+1,su);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++) cin>>a[i];
sort(a+1,a+1+n);
for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
jc[0]=1;
for(int i=1;i<=n;i++) jc[i]=(jc[i-1]%mod*i)%mod; 
if(s[n]==n){
	dp2[2]=1;
	for(int i=3;i<=n;i++){
	dp3[i]=2*dp3[i-1]+dp2[i-1];
	dp2[i]=(jc[i]%mod*ksm(jc[2]%mod*jc[i-2]%mod,mod-2,mod)%mod)%mod;
	}
	cout<<dp3[n];
	return 0;
}
//	for(int i=1;i<=n;i++){
//		
//		
//		
//		if(i>=3){
//			for(int j=1;j<=cnt;j++){
//				if(lp[j]>a[i]){
//				//	cout<<j<<' '<<i<<endl;
//				sum=(sum%mod+1)%mod;	
//				}
//			}
//		}
//		
//		for(int j=cnt;j>=1;j--){
//		///	cout<<j<<' '<<i<<' '<<cnt+1<<' '<<lp[j]<<endl;
//			lp[++cnt]=lp[j]+a[i];
//		}
//		lp[++cnt]=a[i];
//	}

dfs(1,0);

	cout<<sum;
	
	
	
	return 0;
}
