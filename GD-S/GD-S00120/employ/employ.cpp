#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,m,c[505],p[505],ans;char s[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]),p[i]=i;
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		if((!c[i])||(!(s[i]&1)))
		return printf("0"),0;
		return printf("1"),0;
	}
	do
	{
		int sum=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt>=c[p[i]]){cnt++;continue;}
			if(s[i]=='1') sum++;else cnt++;
		}if(sum>=m) ans++;if(ans==mod) ans=0;
	}while(next_permutation(p+1,p+n+1));
	printf("%d",ans);
}
