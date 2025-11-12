#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
long long s[100005],c[100005];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		ans=ans*i%998244353;
	}
	cout<<ans;
}
