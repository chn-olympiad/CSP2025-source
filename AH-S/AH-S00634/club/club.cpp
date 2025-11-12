#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 100010;
int n, a[maxn][4], b[maxn];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		vector<int> C[4];
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3])
			{
				cnt1++;
				C[1].push_back(max(a[i][2],a[i][3])-a[i][1]);
				ans += a[i][1];
			}
			else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3])
			{
				cnt2++;
				C[2].push_back(max(a[i][1],a[i][3])-a[i][2]);
				ans += a[i][2];
			}
			else
			{
				cnt3++;
				C[3].push_back(max(a[i][1],a[i][2])-a[i][3]);
				ans += a[i][3];
			}
		}
		if(cnt1>n/2)
		{
			sort(C[1].begin(),C[1].end());
			for(int i=n/2;i<cnt1;i++)
				ans += C[1][i];
		}
		if(cnt2>n/2)
		{
			sort(C[2].begin(),C[2].end());
			for(int i=n/2;i<cnt2;i++)
				ans += C[2][i];
		}
		if(cnt3>n/2)
		{
			sort(C[3].begin(),C[3].end());
			for(int i=n/2;i<cnt3;i++)
				ans += C[3][i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
