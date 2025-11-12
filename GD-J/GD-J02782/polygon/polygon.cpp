#include<cstdio>
using namespace std;
const long long mod=998244353;
long long n,a[1000009],dp[5009][10009],ans,t[1000009],R[1000009],len;
void sort_(long long l,long long r)
{
	if(l>=r)return;
	long long mid=(l+r)/2;
	sort_(l,mid);
	sort_(mid+1,r);
	long long i=l,j=mid+1,k=0;
	while(i<=mid&&j<=r)
	{
		if(a[i]<a[j])
		{
			++k;
			t[k]=a[i];
			++i;
		}
		else
		{
			++k;
			t[k]=a[j];
			++j;
		}
	}
	while(i<=mid)
	{
		++k;
		t[k]=a[i];
		++i;
	}
	while(j<=r)
	{
		++k;
		t[k]=a[j];
		++j;
	}
	for(i=0;i<k;++i)
	{
		a[i+l]=t[i+1];
	}
}
long long query(long long x,long long y)
{
	long long sum=0;
	for(int i=y+1;i<=10003;++i)
	{
		sum+=dp[x][i];
	}
	return sum%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
	}
	sort_(1,n);
	for(int i=1;i<=n;++i)
	{
		if(a[i]!=a[i+1])
		{
			++len;
			R[len]=i;
		}
	}
	dp[0][0]=1;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<=10003;++j)
		{
			dp[i+1][j]+=dp[i][j];
			if(j+a[i+1]<=10003)dp[i+1][j+a[i+1]]+=dp[i][j];
			else dp[i+1][10003]+=dp[i][j];
		}
		for(int j=0;j<=10003;++j)
		{
			dp[i+1][j]%=mod;
		}
	}
	ans=query(R[1],2*a[1]);
	for(int i=2;i<=len;++i)
	{
		ans+=query(R[i],2*a[R[i]])-query(R[i-1],2*a[R[i]]);
		ans+=mod;
	}
	ans%=mod;
	printf("%lld",ans);
	return 0;
}
