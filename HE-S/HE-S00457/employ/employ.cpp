#include<bits/stdc++.h>
#include <ostream>
#define int long long
using namespace std;
const int N=5e2+7;
const int mod=998244353;

int n,m;
string s;
int c[N];
int sum[N];

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+n+1);
	if(s[0]=='0') sum[1]=1;
	else sum[1]=0;
	for(int i=1;i<s.size();i++)
	{
		if(s[i]=='1') sum[i+1]=sum[i];
		else sum[i+1]=sum[i]+1;
	}
//	for(int i=1;i<=n;i++) cout<<sum[i]<<" "<<c[i]<<"\n";
	if(!sum[n]||(n+m)&1)
	{
		int ans=1,cnt=0;
		for(int i=1;i<=n;i++) if(c[i]) cnt++;
//		cout<<cnt<<"+++\n";
		for(int i=1;i<=cnt;i++) ans=ans*i%mod;
		cout<<ans<<"\n";
		return 0;
	}
	vector<int> ans;
	int cnt=0;
	int x=0;
	for(int i=1;i<=n;i++)
	{
		if(sum[i]<=c[i]) x++;
		else
		{
			if(x) ans.push_back(x),cnt+=x;
			x=0;
		}
	}
	if(cnt<m) cout<<0;
	else cout<<1145141919810%mod<<"\n";
	
	return 0;
}
