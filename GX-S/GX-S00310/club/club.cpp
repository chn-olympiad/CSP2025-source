#include<bits/stdc++.h>
#define ll long long
#define N (int)1e5+10
using namespace std;

ll t;
ll n,ans,cnt;
ll a[N][4],dp[4][N],s[N];
void dfs(ll x,ll y,ll a1,ll a2,ll a3)
{
	if(x>n)
	{
		ans=max(ans,y);
		return;
	}
	if(y+s[n]-s[x-1]<=ans)
		return;
	cnt++;
	if(cnt>=130000000)
	{
		printf("%lld\n",ans);
		exit(0);
	}
	if(a1+1<=n/2)
		dfs(x+1,y+a[x][1],a1+1,a2,a3);
	if(a2+1<=n/2)
		dfs(x+1,y+a[x][2],a1,a2+1,a3);
	if(a3+1<=n/2)
		dfs(x+1,y+a[x][3],a1,a2,a3+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		/*memset(dp,0,sizeof dp);
		memset(mx,0,sizeof mx);*/
		scanf("%lld",&n);
		ans=0;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=3; j++)
				scanf("%lld",&a[i][j]);
			s[i]=s[i-1]+max(a[i][1],max(a[i][2],a[i][3]));
		}
		/*for(ll i=1; i<=n; i++)
		{
			for(ll j=1; j<=3; j++)
			{
				for(ll k=1; k<=min(n/2,i); k++)
				{
					dp[j][k]=max(dp[j][k],max(dp[j][k-1],max(mx[!(i%2)][(j+1)%3],mx[!(i%2)][(j+2)%3]))+a[i][j]);
					if(t==1&&i==3&&j==2&&k==1)
						printf("B%lld B%lld B%lld",dp[j][k-1],mx[!(i%2)][(j+1)%3],mx[!(i%2)][(j+2)%3]);
					mx[i%2][j]=max(mx[i%2][j],dp[j][k]);
				}
			}
			if(i==3&&t==1)
			{
				for(ll j=1; j<=3; j++){
						printf("A%lld ",mx[i%2][j]);
					printf("\n");
				}
			}
		}
		/*if(t==1)
			for(ll i=1; i<=3; i++){
					for(ll k=1; k<=n/2; k++)
						printf("A%lld ",dp[i][k]);
					printf("\n");
			}*/
		dfs(1,0,0,0,0);
		printf("%lld\n",ans);
	}
	return 0;
}
