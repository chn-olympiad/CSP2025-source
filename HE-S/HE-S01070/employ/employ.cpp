#include <bits/stdc++.h>
using namespace std;

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	if(0)cout<<"ÂîË­º±¼û!"; 
	int n,m;
	long long ans=1;
	cin>>n>>m;
	for(int i=n;i>=m;i++)
	{
		ans*=n;
		ans%=998244353;
	}
	cout<<ans;
}
