#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read();

const int N=1e5+10;

bool wcc(int x,int y)
{
	return x>y;
}

void solve()
{
	int n=read(),ans=0;
	int s1[N]={},s2[N]={},s3[N]={};
	for(int i=1;i<=n;i++)
		s1[i]=read(),s2[i]=read(),s3[i]=read();
	if(n==2)
		ans=max(s1[1]+s2[2],max(s1[1]+s3[2],max(s2[1]+s1[2],max(s2[1]+s3[2],max(s3[1]+s2[2],s3[1]+s1[2])))));
	else
	{
		sort(s1+1,s1+1+n,wcc);
		for(int i=1;i<=n/2;i++)
			ans+=s1[i];
	}
	printf("%lld\n",ans);
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)
	{
		solve();
	}
	return 0;
}

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
