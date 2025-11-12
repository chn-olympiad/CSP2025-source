#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,ans,s,Max;
int a[100005];
int f[5005];
signed main(){ 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],Max=max(Max,a[i]);
	sort(a+1,a+n+1);
	s=1,f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=Max;j>=a[i];j--)f[j]+=f[j-a[i]];
		int cnt=0;
		for(int j=1;j<=a[i];j++)cnt+=f[j];
		cnt%=mod;
		ans=(ans-cnt+s+mod)%mod;
		s=(s*2)%mod;
	}
	cout<<ans;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
