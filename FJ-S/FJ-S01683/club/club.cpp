#include<bits/stdc++.h>
using namespace std;
int n;
int a1[200005],a2[200005],a3[200005],dp[200005];
int ans=0;
void dfs(int sum1,int sum2,int sum3,int n1,int n2,int n3,int k)
{
	if(k==n+1)
	{
		ans=max(ans,sum1+sum2+sum3);
		return; 
	}
	if(n1<n/2)dfs(sum1+a1[k],sum2,sum3,n1+1,n2,n3,k+1);
	if(n2<n/2)dfs(sum1,sum2+a2[k],sum3,n1,n2+1,n3,k+1);
	if(n3<n/2)dfs(sum1,sum2,sum3+a3[k],n1,n2,n3+1,k+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	for(int T=1;T<=t;T++)
	{
		cin>>n;
		int h2=0,h3=0;
	    for(int i=1;i<=n;i++)
	    {
		    cin>>a1[i]>>a2[i]>>a3[i];
		    if(a2[i]!=0)h2=1;
		    if(a3[i]!=0)h3=1;
	    }
	    if(h2==0&&h3==0)
	    {
	    	sort(a1+1,a1+1+n);
	    	for(int i=n;i>=n/2;i--)ans+=a1[i];
	    	cout<<ans<<endl;ans=0;
	    	return 0;
		}
	    dfs(0,0,0,0,0,0,1);
	    cout<<ans<<endl;ans=0;
	}
	return 0;
}
