#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,a[N][3];
vector<int> vec[3];
inline void solve() 
{
	cin>>n;
	vec[0].clear(),vec[1].clear(),vec[2].clear();
	int ans = 0;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		int mx = 0,cmx = 0;
		if(a[i][1]>a[i][mx]) cmx = a[i][mx],mx = 1;
		else cmx = max(cmx,a[i][1]);
		if(a[i][2]>a[i][mx]) cmx = a[i][mx],mx = 2;
		else cmx = max(cmx,a[i][2]);
		vec[mx].push_back(a[i][mx]-cmx);
		ans+=a[i][mx];
	}
	for(int i = 0;i<3;i++)
	{
		if(vec[i].size()>n/2)
		{
			sort(vec[i].begin(),vec[i].end());
			for(int j = 0;j<vec[i].size()-n/2;j++)
				ans-=vec[i][j]; 
		}
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;cin>>T;
	while(T--) solve();
	return 0;
}

