#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 505;
const int mod = 998244353;
int n,m;
int a[maxn];
string s;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	
	cin>>s;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	int ans = 1;
	for(int i = 1;i<=n;i++){
		(ans*=i)%=mod;

	}
	cout<<ans;
}
