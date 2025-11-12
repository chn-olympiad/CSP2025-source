#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[100001][4],maxn;
void dfs(ll x,ll ca,ll y,ll cb,ll z,ll cc,ll xb)
{
	if(ca>n/2||cb>n/2||cc>n/2)return;
	if(xb==n+1)maxn=max(maxn,x+y+z);
	dfs(x+a[xb][1],ca+1,y,cb,z,cc,xb+1);
	dfs(x,ca,y+a[xb][2],cb+1,z,cc,xb+1);
	dfs(x,ca,y,cb,z+a[xb][3],cc+1,xb+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		maxn=-1e18;
		cin>>n;
		for(ll i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		dfs(0,0,0,0,0,0,1);
		cout<<maxn<<endl;
	}
	return 0;
}
