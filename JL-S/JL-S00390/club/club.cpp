#include <bits/stdc++.h>
using namespace std;
long long t,n,cnt=0;
long long sa1[20010],sa2[20010],sa3[20010],max_sa[20010];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld%lld%lld",&sa1[i],&sa2[i],&sa3[i]);
			max_sa[i]=max(sa1[i],max(sa2[i],sa3[i]));
			cnt+=max_sa[i];
		}
		printf("%lld\n",cnt);
	}

	return 0;
}
