#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005,M=1e7+5,mod=998244353;
int a[N],dp[M];
int n,sum,ans;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=sum;j>=0;j--)
		{
			if(j>a[i])
			{
				ans+=dp[j];
				if(ans>mod)
				{
					ans-=mod;
				}
			}
			dp[j+a[i]]+=dp[j];
			if(dp[j+a[i]]>mod)
			{
				dp[j+a[i]]-=mod; 
			}
		}
		sum+=a[i];
	}
	cout<<ans;
	return 0;
}
/*
Problem4 [9:30]
DP:wo mei re shui
I invited a O(n*sigma a)'s zuo fa
Maybe only 80 pts
But Zu Gou le
*/
/*
//freopen
//feropen
Although I'm only Grade 9,I think I will tuiyile(Me na me jin)
T4 is so hard that I want to cry
Last,thanks Mr.Liao(Our handmaster when I was Grade 8),Da da di thanks Mrs.He(Wo pa ta kan dao)
*/
