#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans=1,t,fq;
string s;
ll a[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	t=n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)t--;
	}
	if(t<m||n<m)
	{
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=m;i++)
	{
		ans=ans*(t-i+1)%998224353;
	}
	cout<<ans;
	return 0;
}
//0 0 26 43 15 19
//fq:48
