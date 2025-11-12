#include<bits/stdc++.h>
#define ll long long
#define cin std::cin
#define cout std::cout
#define IOS cin.tie(nullptr)->sync_with_stdio(false);
const int N=1e6+5;
const int inf=1e9;
const int mod=998244353;
int n,m;
std::string a;
int c[N];
int tong[N];
int ans=1;
int cnt=-inf;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		tong[c[i]]++;
		cnt=std::max(cnt,c[i]);
	}
	for(int i=1;i<=cnt;i++){
		ans=(ans*tong[i])%mod;
	}
	cout<<ans%mod;
	return 0;
}

