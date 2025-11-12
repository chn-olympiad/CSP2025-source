#include<bits/stdc++.h>
#define I ios_base::sync_with_stdio(0);
#define AK cin.tie(0);
#define CSP cout.tie(0);
#define int long long 
#define mod 998244353
#define endl '\n'
using namespace std;
const int maxn=5010;
int n,a[maxn],s[maxn],f[maxn],ans=0;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	I AK CSP
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		memset(f,0,sizeof(f));
		f[0]=1;
		for(int k=1;k<i;k++){
			for(int j=s[i-1];j>=a[k];j--){
				if(f[j-a[k]]>0) {f[j]+=(f[j-a[k]])%mod; f[j]%=mod;}
			}
		}
		for(int j=a[i]+1;j<=s[i-1];j++){ans+=(f[j])%mod; ans%=mod;}
	}
	cout<<ans%mod;
	return 0;
}

