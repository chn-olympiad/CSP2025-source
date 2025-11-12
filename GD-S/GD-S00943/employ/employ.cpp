#include<bits/stdc++.h>
using namespace std;
#define p 998244353
int n,m,c[501],a[11]={0,1,2,3,4,5,6,7,8,9,10},ans;
char s[1001];
bool flaga;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	do
	{
		int res=0;
		for(int i=1,sum=0;i<=n;i++)
		{
			if(s[i]=='0'||c[a[i]]<=sum)++sum;
			else ++res;
		}
		ans+=res>=m;
	}while(next_permutation(a+1,a+n+1));
	printf("%d\n",ans);
	return 0;
}
