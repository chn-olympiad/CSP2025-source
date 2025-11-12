#include<bits/stdc++.h>
#define int long long
using namespace std;
const int BIG=2e6;
int n,m,cnt=1,a[BIG],ans=1;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])cnt++;
	}
	while((cnt-1)/n!=0)cnt-=n,ans++;
	if(ans%2==1)cout<<ans<<" "<<cnt;
	else cout<<ans<<" "<<n-cnt+1;
	return 0;
}
