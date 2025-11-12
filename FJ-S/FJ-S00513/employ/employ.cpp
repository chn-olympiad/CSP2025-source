#include <bits/stdc++.h>
#define re register
#define ll long long
const int mod=998244353;
const int maxn=505;
using namespace std;
int n,m,c[maxn];
string s;
inline bool check(){
	for(re int i=0;i<s.length()-1;i++){
		if (s[i]=='0') return false;
	}
	return true;
}
inline void deal()
{
	ll res=1;
	for(re int i=2;i<=n;i++){
		res=res*i%mod;
	}
	printf("%lld\n",res%mod);
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> s;
	for(re int i=1;i<=n;i++) cin >> c[i];
	if (check()) deal();
}
