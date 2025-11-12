#include<bits/stdc++.h>
#define modc 998244353
using namespace std;//取模!!
long long n,m,g;
string st;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> st;
	for(int i=1;i<=n;i++){
		cin >> g;
	}long long ans=1;
	for(int i = 1;i<=n;i++){
		ans*=i;
		ans%= modc;
	}cout<<ans;
}