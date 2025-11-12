#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
#define endl '\n'
using namespace std;
const int maxn=5000+5;
int a[maxn];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,ans=0;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<(1<<n);i++)
	{
		int sum=0,maxx=0;
		for(int j=1;j<=n;j++) if((i>>(j-1))&1) sum+=a[j],maxx=max(maxx,a[j]);
		if(sum>maxx*2) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
