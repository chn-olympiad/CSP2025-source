#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt;
const int mod=998244353;
int c[501];
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	cnt=n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)cnt--;
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%mod;
		cerr<<ans<<' '<<i<<endl;
	}
	if(cnt>=m)cout<<ans;
	else cout<<0;
	return 0;
}
