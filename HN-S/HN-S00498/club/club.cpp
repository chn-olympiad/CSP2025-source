#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int t;
int n;
ll a[N];
ll b[N];
ll c[N];
ll maxn=-1;
void dfs(ll s,ll w,ll anum,ll bnum,ll cnum)
{
	if(anum>n/2) return;
	if(bnum>n/2) return;
	if(cnum>n/2) return;
	
	if(s==n)
	{
		maxn=max(maxn,w);
		return ;
	}	
	dfs(s+1,w+a[s+1],anum+1,bnum,cnum);
	dfs(s+1,w+b[s+1],anum,bnum+1,cnum);
	dfs(s+1,w+c[s+1],anum,bnum,cnum+1);
}
bool flag=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		maxn=-1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]==1) flag=1;
			if(b[i]==1) flag=1;
		}
		if(flag==0)
		{
			sort(c+1,c+1+n);
			ll ans=0;
			for(int i=n;i>n-n/2;i--)
			{
				ans+=c[i];
			}
			cout<<ans<<endl;
		}
		else
		{
			dfs(0,0,0,0,0);
			cout<<maxn<<endl;
		}

	}
	return 0;
}
