#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N_ 50
#define P pair<ll,ll>
#define inf 1000000000000
ll read()
{
	char ch=getchar();ll x=0,f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
ll n,T,a[N_][10],ans,dp[N_][N_][N_][N_],cnt,w[1000000]; 
void work()
{
	memset(dp,0,sizeof(dp));ans=0,cnt=0;
	n=read();
	for(int i=1;i<=n;i++)	
		for(int j=1;j<=3;j++)
		{
			a[i][j]=read();
			if(a[i][j]==0)cnt++;
		}
	if(cnt>=2*n)
	{
//		cout<<"here"<<endl;
		ll tot=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
			{
				if(a[i][j])
				w[++tot]=a[i][j];
			}
		sort(w+1,w+1+tot,[](ll x,ll y){
			return x>y;
		});
		for(int i=1;i<=n/2;i++)
		ans+=w[i];
		cout<<ans<<endl;
		return ; 
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n/2;j++)
			for(int h=0;h<=n/2;h++)
				for(int g=0;g<=n/2;g++)
				{
					if(j+1<=n/2)
					dp[i][j][h][g]=dp[i-1][j+1][h][g]+a[i][1];
					if(h+1<=n/2)
					dp[i][j][h][g]=max(dp[i][j][h][g],dp[i-1][j][h+1][g]+a[i][2]);
					if(g+1<=n/2)
					dp[i][j][h][g]=max(dp[i][j][h][g],dp[i-1][j][h][g+1]+a[i][3]);
				}
	for(int j=0;j<=n/2;j++)
			for(int h=0;h<=n/2;h++)
				for(int g=0;g<=n/2;g++)
				ans=max(ans,dp[n][j][h][g]);
	cout<<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		work();
	}
	return 0;
}

