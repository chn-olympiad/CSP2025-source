#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF LLONG_MIN
const int mod=998244353;
int z,a[10005],ok,max1=INF,sum,vis[10005],cnt,max_sum=INF,ans1,count1,e;
int C(int p,int p1)
{
	if(p1>=(p+1)/2)  p1=p-p1;
	int sum=1,sum1=1;
	for(int i=p;i>=p-p1+1;i--)  sum=(sum*i)%mod;
	for(int i=1;i<=p1;i++)  sum1=(sum1*i)%mod;
	return ((sum%mod)/(sum1%mod))%mod;
}
void q(int qq)
{
	e++;
	if(e>=1e8+1e7)
	{
		printf("%lld",ans1%mod);
		exit(0);
	}
	if(cnt>2*max_sum&&count1>=3)  ans1=(ans1+1)%mod;
	if(count1>z)  return ;
	for(int i=qq;i<=z;i++)
	{
		if(vis[i]==0)
		{
			count1++;
			vis[i]=1;
			int max_sum1=max_sum;
			max_sum=max(max_sum,a[i]);
			cnt+=a[i];
			q(i+1);
			count1--;
			vis[i]=0;
			if(max_sum!=max_sum1)  max_sum=max_sum1;
			cnt-=a[i];
		}
	}
}
signed main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&z);
	for(int i=1;i<=z;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]>1)  ok=1;
		sum+=a[i];
		max1=max(max1,a[i]);
	}
	sort(a+1,a+z+1,greater<int>());
	if(z==3)
	{
		if(sum>max1*2)  printf("1");
		else  printf("0");
	}
	else if(ok==0)
	{
		int ans=0;
		for(int i=3;i<=z;i++)  ans=(ans+C(z,i))%mod;
		printf("%lld",(ans%mod)%mod);
	}
	else
	{
		ans1=0;
		q(1);
		printf("%lld",ans1);
	}
	
	return 0;
}
