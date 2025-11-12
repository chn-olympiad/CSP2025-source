#include <bits/stdc++.h>
#define ll long long
const int N=1e5+5;
using namespace std;
ll T,n,a[N][4],b[N];
ll sum,ans;
void dfs(ll x,ll dy,ll de,ll ds)
{
	if(x==n+1)
	{
		ans=max(ans,sum);
		return ;
	}
	for(ll i=1;i<=3;i++)
	{
		if(i==1&&dy==n/2) continue;
		if(i==2&&de==n/2) continue;
		if(i==3&&ds==n/2) return;
		sum+=a[x][i];
		ans=max(ans,sum);
		if(i==1)
			dy++;
		else if(i==2)
		    de++;
		else 
		    ds++;
		dfs(x+1,dy,de,ds);
		sum-=a[x][i];
		if(i==1)
			dy--;
		else if(i==2)
		    de--;
		else 
		    ds--;
	}
	return;
}
bool cmp(ll w,ll e)
{
	return w>e;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
		bool b1=1;
		ans=0;
		sum=0;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=3;j++)
			{
				cin >> a[i][j];
				if(j==2)
				    if(a[i][j]!=0)
				        b1=0;
				if(j==3)
				    if(a[i][j]!=0)
				        b1=0;
			}
		}
		if(b1)
		{
			for(ll i=1;i<=n;i++)
				b[i]=a[i][1];
			sort(b+1,b+1+n,cmp);
			for(ll i=1;i<=n/2;i++)
				ans+=b[i];
			cout << ans;
		}
		else
		{
			dfs(1,0,0,0);
		    cout << ans << endl;
		}
	}
	return 0;
}
