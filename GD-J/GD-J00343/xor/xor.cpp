#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n;
ll k,num=1;
ll a[N];
int vis[N][25];
int b[25];
int sum[25];
int dp[1048757];

void ch(ll x,int y)
{
	if(x==0) return ;
	ll r=1048756;
	int i=0;
    while(x>0)
    {
    	if(x>=r)
    	{
    		vis[y][20-i]=1;
    		i++;
    		x-=r;
    		r/=2;
		}
		else
		{
			r/=2;
			i++;
		}
		if(r==0) break; 
	}
	return ;
}
void bch(ll x)
{
	if(x==0) return ;
	ll r=1048756;
	int i=0;
    while(x>0)
    {
    	if(x>=r)
    	{
    		b[20-i]=1;
    		i++;
    		x-=r;
    		r/=2;
		}
		else
		{
			r/=2;
			i++;
		}
		if(r==0) break; 
	}
	return ;
}

bool check(int l,int r)
{
	for(int j=20;j>=0;j--)
	{
		sum[j]=vis[l][j];
	}
	for(int i=l+1;i<=r;i++)
	{
		for(int j=20;j>=0;j--)
		{
			if(sum[j]==vis[i][j]) sum[j]=1;
			else sum[j]=0;
		}
	}
	
	for(int i=20;i>=0;i--)
	{
		if(sum[i]!=b[i]) return false;
	}
	return true;
	
}

void qujian()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n-i;j++)
		{ 
            int k=i+j;
            
            if(check(i,k)==true)
            {
            	dp[k]=max(dp[k],dp[i]+1);
            	dp[k]=max(dp[k],dp[k-1]);
            	
			}
			else
			{
				dp[k]=max(dp[k],dp[k-1]);
			}
		}
	}
}
signed main()
{
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	cin>>n>>k;
	
	bch(k);
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ch(a[i],i);
	}

	qujian();

	cout<<dp[n]<<endl;
	return 0;
}
