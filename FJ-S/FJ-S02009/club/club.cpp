#include<bits/stdc++.h>
using namespace std;
int t,n,q,pda=1,ans,dp[500005],js[4];
struct arc{
	int l,m,r;
}a[500005]; 
bool cmp(arc a,arc b)
{
	if(a.l!=b.l)
	return a.l>b.l;
	else if(a.m!=b.m)
	return a.m>b.m;
	else
	return a.r>b.r;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].l>>a[i].m>>a[i].r;
			if(a[i].m!=0||a[i].r!=0)pda=0;
		}
		sort(a+1,a+1+n,cmp);
		if(pda){
			for(int i=1;i<=n/2;i++)ans+=a[i].l;
			cout<<ans;
			return 0;
		}
		else for(int i=1;i<=n;i++){
			q=max(a[i].l,max(a[i].m,a[i].r));
			if(q==a[i].l){
				if(js[1]<n/2)
				{
				    dp[i]=dp[i-1]+a[i].l;
				    js[1]++;
				}
				else
				{
				    q=max(dp[i-1]-a[i-1].l+max(a[i-1].m,a[i-1].r)+a[i].l,dp[i-1]+max(a[i].r,a[i].m));
			        if(q==dp[i-1]-a[i-1].l+a[i-1].m||q==dp[i-1]+a[i].m)
			        js[2]++;
			        else  js[3]++;
				}
			}
			else if(q==a[i].m){
				if(js[2]<n/2)
				{
				    dp[i]=dp[i-1]+a[i].m;
				    js[2]++;
				}
				else
				{
				    q=max(dp[i-2]-a[i-1].m+max(a[i-1].l,a[i-1].r)+a[i].m,dp[i-1]+max(a[i].l,a[i].r));
			        if(q==dp[i-1]-a[i-1].m+a[i-1].l||q==dp[i-1]+a[i].l)
			        js[1]++;
			        else  js[3]++;
				}
			}
			else
			{
				if(js[3]<n/2)
				{
				    dp[i]=dp[i-1]+a[i].r;
				    js[3]++;
				}
				else
				{
				    q=max(dp[i-1]-a[i-1].r+max(a[i-1].m,a[i-1].l)+a[i].r,dp[i-1]+max(a[i].m,a[i].l));
			        if(q==dp[i-1]-a[i-1].r+a[i-1].m||q==dp[i-1]+a[i].m)
			        js[2]++;
			        else  js[1]++;
				}
			}
		}
		cout<<dp[n]<<endl;
    }
	return 0;
} 
