#include<bits/stdc++.h>
#define ll long long 
#define LOCAL 0
#define ONLINE 1
using namespace std;
const int N=1e4+44,mod=998244353;
ll n,a[N],f[N],cnt[N],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	#if LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	#if ONLINE
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	#endif
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	cnt[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[n]+1;j>=0;j--){
			if(j>a[i])f[i]=(f[i]+cnt[j])%mod;
			cnt[min(a[n]+1,j+a[i])]=(cnt[j]+cnt[min(a[n]+1,j+a[i])])%mod;
		}
	//	for(int j=0;j<=a[n]+1;j++)cout<<cnt[j]<<' ';cout<<'\n';
	}
	for(int i=1;i<=n;i++)ans=(ans+f[i])%mod;
//	cout<<'\n';for(int i=1;i<=n;i++)cout<<f[i]<<' ';
	cout<<ans;
} 
