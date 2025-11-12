#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=1ll;
const int range=505;
const long long mod=998244353;
char c[range];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d ",&n);
	for(int i=1;i<=n;i++)
	{
		cin >> c[i];
		(ans*=i)%=mod;
	}
	printf("%lld",ans);
	return 0;
}
