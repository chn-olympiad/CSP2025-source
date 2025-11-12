#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mid=998244353,ans,n,m;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	ans=n;
	for(ll i=2;i<=n;i++)
	{
		ans=ans*n%mid;
		
	}
	cout<<ans;
	return 0;
}
 
