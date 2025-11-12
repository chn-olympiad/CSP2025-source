#include<cstdio>
#include<algorithm>
using namespace std;

#define N 505

const int mod=998244353;

namespace code
{
	int n;
	int a[N],c[N];
	
	signed main()
	{
		scanf("%d",&n);
		bool t=1;
		for(int i=1;i<=n;++i)
		{
			char c=getchar();
			if(c=='0') t=0;
			else if(c=='1') a[i]=1;
			else --i;
		}
		if(t)
		{
			int ans=1;
			int tot=0;
			for(int i=1;i<=n;++i)
				scanf("%d",&c[i]),
				tot+=(c[i]==0);
			for(int i=1,j=n-tot;i<=tot;++i,--j)
				ans=(long long)ans*j%mod;
			for(int i=1;i<=n-tot;++i)
				ans=(long long)ans*i%mod;
			printf("%d",ans);
			return 0;
		}
		return 0;
	}
}

signed main()
{
	// freopen("employ3.in","r",stdin);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	code::main();
	return 0;
}