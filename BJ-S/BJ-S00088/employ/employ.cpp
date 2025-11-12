#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int N=507;
int n, m;
string str;
int s[N], c[N];
ll jc[N], inv[N];
ll ksm(ll x, ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++)
		s[i]=str[i-1]-'0';
	bool flag=1;
	for(int i=1;i<=n;i++)
		if(s[i]==0)
			flag=0;
	if(flag==1){
		jc[0]=inv[0]=1;
		for(ll i=1;i<=n;i++)
			jc[i]=jc[i-1]*i%mod;
		cout<<jc[n]<<endl;
		return 0;
	}
	return 0;
}