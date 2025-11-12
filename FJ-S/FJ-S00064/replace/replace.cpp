#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mpi make_pair
#define fi first
#define se second
using namespace std;
const int maxn=2e5+10;
const int maxm=5e6+10;
const int base=13331;
const int mod=1e9+7;
const int INF=1e18;
int n,q,pw[maxm],len[maxn];
string s[maxn][2],t1,t2;
int h[maxn][2];
pii x[maxn];
vector <int> init(string s)
{
	vector <int> h;
	int len=s.size(),lst=0;
	for (int i=0;i<len;i++) lst=(lst*base%mod+s[i])%mod,h.push_back(lst);
	return h;
}
int find(vector <int> h,int l,int r)
{
	return (h[r]-(l==0?0:h[l-1]*pw[r-l+1]%mod)+mod)%mod;
}
void work1()
{
	pw[0]=1;
	for (int i=1;i<=maxm-10;i++) pw[i]=pw[i-1]*base%mod;
	for (int i=1;i<=n;i++)
	{
		cin >> s[i][0] >> s[i][1];
		len[i]=s[i][0].size();
		for (int j=0;j<s[i][0].size();j++) h[i][0]=(h[i][0]*base%mod+s[i][0][j])%mod,h[i][1]=(h[i][1]*base%mod+s[i][1][j])%mod;
	}
	while (q--)
	{
		cin >> t1 >> t2;
		int l=0,r=t1.size()-1;
		while (t1[l]==t2[l]) l++;
		while (t1[r]==t2[r]) r--;
		vector <int> h1,h2;
		h1=init(t1);
		h2=init(t2);
		int ans=0;
		for (int i=1;i<=n;i++) for (int j=max(0ll,r-len[i]+1);j<=min((int)t1.size()-len[i],l);j++) ans+=(find(h1,j,j+len[i]-1)==h[i][0]&&find(h2,j,j+len[i]-1)==h[i][1]);//,cout << find(h1,j,j+len[i]-1) << " " << h[i][0] << " " << find(h2,j,j+len[i]-1) << " " << h[i][1] << "\n";
		cout << ans << "\n";
	}
}
void work2()
{
	for (int i=1;i<=n;i++)
	{
		cin >> s[i][0] >> s[i][1];
		int d1=0,d2=0;
		while (s[i][0][d1]=='a') d1++;
		while (s[i][1][d2]=='a') d2++;
		x[i]=mpi(d1-d2,d1);
	}
	sort(x+1,x+n+1);
	while (q--)
	{
		cin >> t1 >> t2;
		int d1=0,d2=0;
		while (t1[d1]=='a') d1++;
		while (t2[d2]=='a') d2++;
		cout << (upper_bound(x+1,x+n+1,mpi(d1-d2,d1))-x)-(upper_bound(x+1,x+n+1,mpi(d1-d2-1,INF))-x) << "\n";
	}
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> q;
	work1();
	return 0;
}
/*
5 1
ab ba
aab aba
aaab aaba
aaaab aaaba
ba ab
aaab aaba
*/
