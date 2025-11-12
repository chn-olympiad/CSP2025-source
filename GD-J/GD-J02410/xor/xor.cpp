#include<bits/stdc++.h>
using namespace std;
long long n,k,a[505000],ans;
bool vis[505000];
void dfs(long long len,long long maxlen)
{
	if(len>maxlen)
	{
		return;
	}
	for(long long l=1;l<=n-len+1;l++)
	{
		long long r=l+len-1,num=a[l];
		for(long long i=l+1;i<=r;i++)
		{
			if(vis[i]==false)
			{
				num=-1;
				break;
			}
			num=a[i] xor num;
		}
		if(num==k)
		{
			for(long long i=l;i<=r;i++)
			{
				vis[i]=false;
			}
			ans++;
		}
	}
	long long length=0,mlen=0;
	for(long long i=1;i<=n;i++)
	{
		if(vis[i]==true)
		{
			length++;
		}
		else
		{
			mlen=max(mlen,length);
			length=0;
		}
	}
	mlen=max(mlen,length);
	maxlen=mlen;
	dfs(len+1,maxlen);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(vis,true,sizeof(vis));
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	dfs(1,n);
	printf("%lld",ans);
	return 0;
}
