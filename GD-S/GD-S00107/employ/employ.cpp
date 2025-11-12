#include<iostream>
#define LL long long
using namespace std;
const int maxn = 510;
const int mod = 998244353;
LL fac[maxn],a[maxn],ifac[maxn];
LL cnt[maxn];
LL power(LL u,int v){
	int ans = 1;
	while(v){
		if(v % 2 == 1){
			ans = ans * u % mod;
		}
		u = u * u % mod;
		v /= 2;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	fac[1] = 1;
	for(int i = 2;i<=500;i++){
		fac[i] = fac[i - 1] * i % mod;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	ifac[500] = power(fac[500],mod - 2);
	for(int i=500;i > 1;i --){
		ifac[i - 1] = ifac[i] * i % mod;
	}
	LL sum = 1;
	for(int i=0;i<=n;i++){
		if(!cnt[i])continue;
		sum = sum * ifac[cnt[i]] % mod;
	}
	cout<<sum<<endl;
	return 0;
}
