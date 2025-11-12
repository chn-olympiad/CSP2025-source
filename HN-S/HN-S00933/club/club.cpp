#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int t,n,a[N][9],dp[205][105][105],ans,tepan;
struct node{
	int b,c;
}b[N];
bool cmp(node x,node y)
{
	return x.b-x.c>y.b-y.c;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=tepan=0;
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i].b=a[i][1];b[i].c=a[i][2];
			tepan=max(tepan,a[i][3]);
		}
		if(tepan==0)
		{
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n/2;i++)
				ans+=b[i].b;
			for(int i=n/2+1;i<=n;i++)
				ans+=b[i].c;
		}
		else if(n<=200)
		{
			for(int i=1;i<=n;i++)
				for(int j=0;j<=n/2;j++)
					for(int k=0;k<=n/2;k++)
					{
						if(j+k>i||i-j-k>n/2)continue;
						if(j!=0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
						if(k!=0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
						if(i-j-k<=n/2&&j+k<i)
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
						if(i==n)ans=max(ans,dp[i][j][k]);
					}
		}
		else{
			//pianfen
			for(int i=1;i<=n;i++)
				ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		cout<<ans<<'\n';
	}
	return 0;
}
