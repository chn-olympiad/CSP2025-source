#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e2+5;
const int mod=998244353;

char s[N];
int c[N];

signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n,m,ans=1,tot;
	std::cin>>n>>m;
	std::cin>>s+1;
	tot=n;
	for(int i=1;i<=n;++i) 
		std::cin>>c[i],tot-=(c[i]==0);
	for(int i=1;i<=n;++i) 
		ans=ans*i%mod;
	//std::cout<<n<<" "<<tot<<'\n';
	std::cout<<(ans%mod+mod)%mod<<'\n';
	return 0;
}