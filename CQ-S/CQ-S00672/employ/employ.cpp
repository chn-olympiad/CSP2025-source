#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 1010
#define inf 0x3f3f3f3f3f3f3f3f
int n,m;
string ss;
int c[maxn];
pair<int,int>cc[maxn];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>ss;
	for(int i=1;i<=n;++i) cin>>c[i];
	for(int i=1;i<=n;++i)
	{
		cc[i].first=i;
		cc[i].second=c[i];
	}
	sort(cc+1,cc+n+1);
	int ans=0;
	do{
		int cnt=0;
		for(int i=1;i<=n;++i)
		{
			cnt+=(ss[i-1]=='1')&&(cc[i].second>(i-cnt-1));
		}
		ans+=(cnt>=m);
	}while(next_permutation(cc+1,cc+n+1));
	cout<<ans<<'\n';
	return 0;
}

