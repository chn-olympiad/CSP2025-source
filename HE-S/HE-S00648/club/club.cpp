#include<bits/stdc++.h>
using namespace std;
const int maxn=100050;
struct node{
	int t1,t2,di;
}kk[maxn];
int n,a[maxn][10],ans,k[maxn],dp[205][205][205];
bool check1()
{
	for(int i=1;i<=n;i++) if(a[i][2]!=0||a[i][3]!=0) return false;
	return true;
}
bool check2()
{
	for(int i=1;i<=n;i++) if(a[i][3]!=0) return false;
	return true;
}
void dfs(int k,int s1,int s2,int s3,int sum)
{
    if(s1>n/2||s2>n/2||s3>n/2) return;
    if(k==n+1)
    {
        ans=max(ans,sum);
        return;
    }
    dfs(k+1,s1+1,s2,s3,sum+a[k][1]);
    dfs(k+1,s1,s2+1,s3,sum+a[k][2]);
    dfs(k+1,s1,s2,s3+1,sum+a[k][3]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T; cin>>T;
    while(T--)
    {
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) cin>>a[i][j];
        if(n<=10)
        {
            ans=0;
            dfs(1,0,0,0,0);
            cout<<ans<<endl;
        }
    	else if(check1())
    	{
    		for(int i=1;i<=n;i++) k[i]=a[i][1];
    		sort(k+1,k+n+1,greater<int>());
    		int sum=0;
    		for(int i=1;i<=n/2;i++) sum+=k[i];
    		cout<<sum<<endl;
		}
		else if(n<=200)
		{
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=min(n/2,i);j++)
				{
					for(int k=0;k<=min(n/2,i-j);k++)
					{
						int l=i-j-k;
						if(l>n/2) continue;
						if(j!=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
						if(k!=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
						if(k+j<i) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
					}
				}
			}
			int ans=0;
			for(int j=0;j<=n/2;j++)
			{
				for(int k=0;k<=n/2;k++)
				{
					int l=n-j-k;
					if(l>n/2) continue;
					ans=max(ans,dp[n][j][k]); 
				}
			}
			cout<<ans<<endl;
		}
    }
    return 0;
}
