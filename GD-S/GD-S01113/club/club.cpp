#include<bits/stdc++.h>
using namespace std;
int t,n,k1,k2,k3;
long long dp[10005];
struct node
{
	int a,b,c;
}r[10005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t>0)
	{	
		memset(dp,0,sizeof(dp));
		t--;
		cin>>n;
		k1=k2=k3=n/2;
		long long sum=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>r[i].a>>r[i].b>>r[i].c;
		}
		for(int i=1;i<=n;i++)
		{
			if(k1>=1&&(r[i].a>r[i].b&&r[i].a>r[i].c) )
			{
				k1--;
				dp[i]=max(dp[i],dp[i-1]+r[i].a);
			}
			if(k2>=1&&(r[i].b>r[i].a&&r[i].b>r[i].c)) 
			{
				k2--;
				dp[i]=max(dp[i],dp[i-1]+r[i].b);
			}
			if(k3>=1&&(r[i].c>r[i].a&&r[i].c>r[i].b)) 
			{
				k3--;
				dp[i]=max(dp[i],dp[i-1]+r[i].c);
			}
		}
		cout<<dp[n]<<endl;
	}
return 0;
} 
