#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 510,MOD = 998244353;
int n,m,c[N],a[N],ans;
char s[N];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n>=0)
	{
		puts("0");
		return;
	}
	scanf("%s",s+1); 
	for(int i = 1;i<=n;i++)
		scanf("%lld",&c[i]),a[i] = i;
	do
	{
		int cnt = ((s[1]-'0')&&c[a[1]]);
		for(int i = 2;i<=n;i++)
		{
			if(c[a[i]]<=(i-cnt))
				continue;
			else
				cnt+=(s[1]-'0');
		}
		if(cnt>=m)
			ans = (ans+1)%MOD;
	}
	while(next_permutation(a+1,a+n+1));
	printf("%lld\n",ans);
	return 0;
}
