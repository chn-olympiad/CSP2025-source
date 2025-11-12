#include<cstdio>
#include<algorithm>
using namespace std;
constexpr int N=20,M=998244353;
int c[N+5],p[N+5];
char s[N+5];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=0;
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",c+i);
		p[i]=i;
	}
	if(n>11)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]<=cnt||s[i]=='0')
				cnt++;
		}
		if(n-cnt>=m)
		{
			cnt=1;
			for(int i=1;i<=n;i++)
				cnt=(long long)cnt*i%M;
			printf("%d",cnt);
		}
		else
			printf("0");
		return 0;
	}
	do
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(c[p[i]]<=cnt||s[i]=='0')
				cnt++;
		}
		if(n-cnt>=m)
			ans++;
	}while(next_permutation(p+1,p+n+1));
	printf("%d",ans);
	return 0;
}
//100+56+25+28
