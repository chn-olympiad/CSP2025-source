#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t;
ll ans=-1;
ll n;
ll a[100010],b[100010],c[100010];
void dfs(ll ci,ll sum,ll aa,ll bb,ll cc,ll xi)
{
	if(ci==n)
	{
		if(aa<=xi&&bb<=xi&&cc<=xi)
		{ 
			ans=max(ans,sum);
		}
		return;
	} 
	ci+=1;
	dfs(ci,sum+a[ci],aa+1,bb,cc,xi);
	dfs(ci,sum+b[ci],aa,bb+1,cc,xi);
	dfs(ci,sum+c[ci],aa,bb,cc+1,xi);
}
int main()
{
	freopen("club.in","r","stdin");
	freopen("club.out","w","stdout");
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(0,0,0,0,0,n/2);
		cout<<ans<<endl;
		ans=-1;
	}
	return 0;
}

