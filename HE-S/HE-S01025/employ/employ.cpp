#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int mod=998244353;
ll n,m,js[2],te,cnt,ans;
ll a[502];
string s;
ll jc[502],inv[502];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	jc[1]=1;
	inv[0]=1;
	inv[1]=1;
	for(int i=2;i<=n;i++)jc[i]=jc[i-1]*i%mod;
	for(int i=2;i<=n;i++)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n;i++)inv[i]=inv[i]*inv[i-1]%mod;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		te=s[i]-'0';
		js[te]++;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(cnt>=a[i])cnt++;
	}
	cnt=n-cnt;
	if(cnt>=m){
		ans=jc[n]%mod;
	}else{
		ans=0;
	}
	printf("%lld",ans);
}
