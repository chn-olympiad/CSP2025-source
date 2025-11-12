#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ll long long
using namespace std;
const ll MOD=998244353;
const int N=5005,MAXN=5000;
int a[N];
ll f[N],s[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll ans=0,sum=0;
	f[0]=1;
	for(int i=1;i<=n;i++){
		(ans+=s[a[i]+1]+sum)%=MOD;
		sum=sum*2%MOD;
		for(int j=MAXN;j>MAXN-a[i];j--) (sum+=f[j])%=MOD;
		for(int j=MAXN;j>=a[i];j--) (f[j]+=f[j-a[i]])%=MOD; 
		for(int j=MAXN;j>=0;j--) s[j]=(s[j+1]+f[j])%MOD;
	}
	cout<<ans<<'\n';
	return 0; 
}
