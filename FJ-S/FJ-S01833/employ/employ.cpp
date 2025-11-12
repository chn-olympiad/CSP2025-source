#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod=998244353;
string s;
int c,n,m;
int ans=1;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,j;
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(i=1;i<=n;i++)
		scanf("%lld",&c);
	for(i=1;i<=n;i++)
		ans=ans*i%Mod;
	printf("%lld",ans);
	return 0;
}
