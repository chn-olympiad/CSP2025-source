#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+6;
int n;
typedef pair<int,int> pii;
pii a[maxn][3];
int cnt[3];
vector<int>b[3];
void solve()
{
	b[0].clear();
	b[1].clear();
	b[2].clear();
	int ans=0;
	cnt[0]=cnt[1]=cnt[2]=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<3;j++)a[i][j].second=j,cin>>a[i][j].first;
		sort(a[i],a[i]+3);
		cnt[a[i][2].second]++;
		ans+=a[i][2].first;
		b[a[i][2].second].push_back(a[i][2].first-a[i][1].first);
	}
	int maxx=max(cnt[0],max(cnt[1],cnt[2])),id;
	n/=2;
	if(maxx<=n){cout<<ans<<'\n';return;}
	maxx-=n;
	if(cnt[0]>n)id=0;
	if(cnt[1]>n)id=1;
	if(cnt[2]>n)id=2;
	sort(b[id].begin(),b[id].end());
	while(maxx)ans-=b[id][--maxx];
	cout<<ans<<'\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}