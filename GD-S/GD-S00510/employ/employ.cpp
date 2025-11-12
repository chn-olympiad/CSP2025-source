#include<bits/stdc++.h>
#define max(a,b) (a>b?a:b)
#define ll long long
using namespace std;
const int M=505,mod=998244353;
int n,m,a[M],bj[M],b[M],flag;
ll ans,sum;
char s[M];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]),b[i]=i;
	do
	{
		int cnt=0,sum=0;
		for(int i=1;i<=n;++i)
			if(cnt>=a[b[i]]||s[i]=='0')cnt++;
			else sum++;
		if(sum>=m)ans++;
	}while(next_permutation(b+1,b+1+n));
//	dfs(0);
	printf("%lld",ans);
//	for(int i=1;i<=n;++i)
//	{
//		if(s[i]=='0')flag=1;
//	}
//	if(!flag)
//	{
//		for(int i=1;i<=n;++i)
//			(ans*=1ll*i)%=mod;
//		printf("%lld",ans);
//		return 0;
//	}
	return 0;
}
