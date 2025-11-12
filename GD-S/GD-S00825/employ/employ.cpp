#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,a[1005],ans;
string s;
struct node{
	int idx,q,new1;
}d[1005];
signed main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&d[i].q);
		d[i].idx=i;
	}
	if(m==1)
	{
		ans=1;
		for(int i=1;i<=n;i++)  ans=(ans*i)%mod;
		printf("%lld",ans);
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(d[i].q==0)
			{
				printf("0");
				return 0;
			}
		}
	}
	int ok=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='1')
		{
			ok=1;
			break;
		}
	}
	if(ok==0)
	{
		ans=1;
		int sum=0;
		for(int i=1;i<=n;i++)  if(d[i].q==0)  sum++;
		for(int i=1;i<=n-sum;i++)  ans=(ans*i)%mod;
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=n;i++)  a[i]=i;
	do
	{
		int sum=0,temp=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(d[i].idx==a[j])
				{
					d[i].new1=d[j].q;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0')
			{
				temp++;
				continue;
			}
			if(temp>=d[i].new1)
			{
				temp++;
				continue;
			}
			if(s[i-1]=='1')  sum++;
		}
		if(sum>=m)  ans=(ans+1)%mod;
	}while(next_permutation(a+1,a+n+1));
	printf("%lld",ans);
	
	return 0;
}
