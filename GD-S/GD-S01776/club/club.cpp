#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e5+10;

int n,a[N][4],mx[N],mn[N],cnt[N],p[N],ans;
void solve()
{
	cin>>n;
	cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=n;i++) a[i][1]=a[i][2]=a[i][3]=mx[i]=mn[i]=p[i]=ans=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=3;j++)
	{
		cin>>a[i][j];
		if(a[i][j]>a[i][mx[i]])
		{
			mn[i]=mx[i];
			mx[i]=j;
		}
		else if(a[i][j]>a[i][mn[i]]) mn[i]=j;
	}
	for(int i=1;i<=n;i++) cnt[mx[i]]++,ans+=a[i][mx[i]];
	for(int i=1;i<=3;i++) if(cnt[i]>(n/2))
	{
		int t=0;
		for(int j=1;j<=n;j++) if(mx[j]==i) p[++t]=a[j][mn[j]]-a[j][mx[j]];
		sort(p+1,p+t+1,greater<int>());
		for(int j=1;j<=cnt[i]-(n/2);j++) ans+=p[j];
		break;
	}
	cout<<ans<<endl;
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}
