#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 510;
const int mod = 998244353;
int n,m,c[N];
string s;
bool f=1;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='0') f=0;
	}
	if(f){
		ll ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		cout << ans << '\n';return 0;
	}
	if(m==n && !f){cout << 0 << '\n';return 0;}
	if(m>18){cout << 0 << '\n';return 0;}
	return 0;
}

