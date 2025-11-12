#include <iostream>
#include <unordered_map>
using namespace std;
namespace GY2025YY
{
	const int N=500003;
	unordered_map<int,int> id;
	int n,m,k,sum[N];
	int main()
	{
		freopen("xor.in", "r", stdin);
		freopen("xor.out","w",stdout);
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&m);
			sum[i]=sum[i-1]^m;
		}
		int lst=1,ans=0;id[0]=1;
		for (int i=1;i<=n;++i)
		{
			if (id[sum[i]^sum[(ans==0?0:lst)]^k]>=lst) lst=i,++ans;
			id[sum[i]^sum[(ans==0?0:lst)]]=i;
		}
		printf("%d",ans);
		return 0;
	}
}
int main()
{
	return GY2025YY::main();
}

