#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6+10;
const ll mod = 998244353;
ll f[N],dp[N];
ll n,a[N],m,ans=0;
inline ll read(){
	int x=0,f=1;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f = -1;
		ch = getchar();
	}
	while('0'<=ch&&ch<='9'){
		x = x*10+ch-'0';
		ch = getchar();
	}
	return x*f;
}
bool cmp(ll x,ll y){
	return x<y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		a[i] = read();
		m = m+a[i];
	}
	sort(a+1,a+n+1,cmp);
	f[0] = 1;
	for(ll i=1;i<=n;i++){
		if(i>=3){
			for(ll j=a[i]+1;j<=m;j++){		
				ans = (ans+f[j])%mod;
			}
		}
		for(ll j=m;j>=0;j--){
			if(j-a[i]>=0){
				f[j] = (f[j]+f[j-a[i]])%mod;
			}
		}
//		for(ll j=1;j<=m;j++){
//			cout<<f[j]<<" ";
//		}
//		cout<<endl;
	}
	cout<<ans%mod;
	return 0;
}
/*
5
1 2 3 4 5

5
2 2 3 8 10
*/
