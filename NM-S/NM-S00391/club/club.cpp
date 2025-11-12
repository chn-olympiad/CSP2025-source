#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt[4],ans;
int a[100005][4];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T__;
	cin>>T__;
	while(T__--)
	{
	    cin>>n;
	    ans=0;
	    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            int maxx=-1;
            for(int j=1;j<=3;j++)
            {
                maxx=max(maxx,a[i][j]);
            }
            ans+=maxx;
        }
        cout<<ans<<"\n";
	}
	return 0;
}
