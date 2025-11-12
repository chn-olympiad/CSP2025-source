#include<bits/stdc++.h>
#define N 1000005
using namespace std;
int T,n;
struct node
{
	int a,b,c,duc,maxduc,lar,sec,lit;
};
node dt[N];
int dp[N][4],k[N],ans[N];
bool cmp(node n1,node n2)
{
	if(n1.duc!=n2.duc) return n1.duc>n2.duc;
	if(n1.maxduc!=n2.maxduc) return n1.maxduc>n2.maxduc;
	if(n1.lar!=n2.lar) return n1.lar>n2.lar;
	if(n1.sec!=n2.sec) return n1.sec>n2.sec;
	return n1.lit>n2.lit;
}
int main()
{
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>dt[i].a>>dt[i].b>>dt[i].c;
			dt[i].lar=max(max(dt[i].a,dt[i].b),dt[i].c);
			if(dt[i].a==dt[i].lar)
			{
				dt[i].duc=dt[i].a-max(dt[i].b,dt[i].c);
				dt[i].sec=max(dt[i].b,dt[i].c);
				dt[i].lit=min(dt[i].b,dt[i].c);
				dt[i].maxduc=dt[i].lar-dt[i].lit;
			}
			else if(dt[i].b==dt[i].lar)
			{
				dt[i].duc=dt[i].b-max(dt[i].a,dt[i].c);
				dt[i].sec=max(dt[i].a,dt[i].c);
				dt[i].lit=min(dt[i].a,dt[i].c);
				dt[i].maxduc=dt[i].lar-dt[i].lit;
			}
			else dt[i].duc=dt[i].c-max(dt[i].a,dt[i].b),dt[i].sec=max(dt[i].a,dt[i].b),dt[i].lit=min(dt[i].a,dt[i].b),dt[i].maxduc=dt[i].lar-dt[i].lit;
		}
		sort(dt+1,dt+1+n,cmp);
		dp[1][1]=dt[1].a;
		dp[1][2]=dt[1].b;
		dp[1][3]=dt[1].c;
		if(dp[1][1]>dp[1][2]&&dp[1][1]>dp[1][3])
		{
			ans[1]=dp[1][1];
			k[1]++;
		}
		else if(dp[1][2]>dp[1][1]&&dp[1][2]>dp[1][3])
		{
			ans[1]=dp[1][2];
			k[2]++;
		}
		else
		{
			ans[1]=dp[1][3];
			k[3]++;
		}		
		for(int i=2;i<=n;i++)
		{
			if(k[1]<n/2) 
				dp[i][1]=ans[i-1]+dt[i].a;
			if(k[2]<n/2)
				dp[i][2]=ans[i-1]+dt[i].b;
			if(k[3]<n/2)
				dp[i][3]=ans[i-1]+dt[i].c;
			if(dp[i][1]>dp[i][2]&&dp[i][1]>dp[i][3])
			{
				ans[i]=dp[i][1];
				k[1]++;
			}
			else if(dp[i][2]>dp[i][1]&&dp[i][2]>dp[i][3])
			{
				ans[i]=dp[i][2];
				k[2]++;
			}
			else
			{
				ans[i]=dp[i][3];
				k[3]++;
			}
		}
		cout<<ans[n]<<"\n";
		for(int i=1;i<=n;i++)
		{
			k[i]=0;
			ans[i]=0;
			dp[i][1]=dp[i][2]=dp[i][3]=0;
		}
	}
	return 0;
 } 