#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n,ans=0,a[N][5],s[5],b[N];
void dfs(ll x,ll cnt)
{
	if(x==n+1)
	{
		ans=max(ans,cnt);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(s[i]>=n/2)continue;
		s[i]++;
		dfs(x+1,cnt+a[x][i]);
		s[i]--;
	}
}
void sol()
{
	bool f1=true;
	ans=0;
	cin>>n;
	s[1]=s[2]=s[3]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		b[i]=a[i][1];
		if(a[i][2]!=0||a[i][3]!=0)f1=false;
	}
	sort(b+1,b+n+1,greater<int>() );
	if(f1)
	{
		for(int i=1;i<=n/2;i++)ans+=b[i];
		cout<<ans<<endl;
		return ;
	}
	dfs(1,0);
	cout<<ans<<endl;
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	while(cin>>t)while(t--)sol();
	return 0;
}
