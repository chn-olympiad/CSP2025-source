#include<iostream>
#include<algorithm>
using namespace std;
int n,m,ans=0;
char s[12];
int c[12],a[12];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	int times=1;
	for(int i=1;i<=n;i++)
	{
		times*=(a[i]=i);
		scanf("%d",&c[i]);
	}
	for(int i=0;i<times;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)cnt+=(s[j]=='0'||cnt>=c[a[j]]);
		ans+=(cnt<=n-m);
		next_permutation(a+1,a+n+1);
	}
	printf("%d\n",ans%998244353);
	return 0;
}
