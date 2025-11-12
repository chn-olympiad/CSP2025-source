#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
#define maxn 20005
#define mod 998244353
ll n,m,t,a[maxn],b[maxn],c[maxn],o[maxn],ans=0;
string c1;
void dfs(ll x,ll y,ll z)
{
	if(x>n)
	{
		//cout<<z<<' ';
		
		//cout<<x<<' '<<y<<' '<<z<<'\n';
		if(z>=m)
		{
			//cout<<'\n';cout<<z<<' ';
			//for(int i=0;i<n;i++)cout<<o[i]<<' ';
			ans++;
			ans%=mod;
		}
		return;
	}
	if(n-x+1+z<m)return;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==1)continue;
		b[i]=1;
		int flag=0,flag2=0;
		if(a[i]<=y)flag=1;
		else if(c[x]==1)flag2=1;
		else flag=1;
		o[x]=i;
		dfs(x+1,y+flag,z+flag2);
		b[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	cin>>c1;
	for(int i=0;i<n;i++)c[i+1]=int(c1[i])-48;
	//for(int i=1;i<=n;i++)cout<<c[i]<<' ';
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
