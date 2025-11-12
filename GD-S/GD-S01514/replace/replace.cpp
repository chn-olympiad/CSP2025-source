#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 0x3f3f3f3f
#define PII pair<int,int>
#define rep(k,a,b) for (int k = a;k <= b;k++)
#define all(a) a.begin(),a.end()
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define vct vector
#define endl '\n'
#define sz(a) ((int)a.size())
#define rof(k,a,b) for (int k = a;k >= b;k--)
#define ull unsigned ll
const int N = 2e5+5,P = 13331;

int n,q;
string s1[N],s2[N];

void solvemain()
{
	cin>>  n >> q;
//	if (n > 2000)
//	{
////		map<array<int,3>,int> mp,mp2;
//		set<array<int,3> > s[N];
//		for (int i = 1;i <= n;i++)
//		{
//			cin >> s1[i] >> s2[i];
//			s1[i] = ' ' + s1[i];s2[i] = ' ' + s2[i];
//			int len  =sz(s1[i]) - 1;
//			int id1 = -1,id2 = -1;
//			for (int j = 1;j <= len;j++)
//			{
//				if (s1[i][j] == 'b') id1 = i;
//				if (s2[i][j] == 'b') id2 = i;
//			}
//			int l = min(id1 - 1,len - id2);int r = max(id1-1,len-id2);
//			s[id1-id2].insert({l,r});
//		}
//		for (int i = 1;i <= q;i++)
//		{
//			string t1,t2;
//			cin >> t1 >> t2;
//			t1 = ' ' + t1;t2 = ' ' + t2;
//			int len = sz(t1) - 1;
//			int id1 = -1,id2 = -1;
//			for (int j = 1;j <= len;j++)
//			{
//				if (t1[j] == 'b') id1 = i;
//				if (t2[j] == 'b') id2 = i;
//			}
////			int ans = mp2[id1 - id2];
//			int l = id1 - 1,r = len - id2;
//			for (int k = )
//		}
//		return;
//	}
	map<pair<ull,ull>,int> mp;
	for (int i = 1;i <= n;i++)
	{
		cin >> s1[i] >> s2[i];
		s1[i] = ' ' + s1[i];s2[i] = ' ' + s2[i];
		int len  =sz(s1[i]) - 1;
		ull h1 = 0,h2 = 0;
		for (int j = 1;j <= len;j++)
			h1 = h1 * P + s1[i][j],h2 = h2 * P + s2[i][j];
		mp[{h1,h2}]++;
	}
	rep(i,1,q)
	{
		string t1,t2;
		cin >> t1 >> t2;
		t1 = ' ' + t1;t2 = ' ' + t2;
		int len = sz(t1) - 1;
		int l = -1,r = -1;
		for (int i = 1;i <= len;i++)
			if (t1[i] != t2[i])
			{
				if (l == -1)l=i;
				r = i;
			}
		ll ans=0;
		for (int i = 1;i <= l;i++)
		{
			ull h1 = 0,h2 = 0;
			for (int j = i;j <= r-1;j++)
			{
				h1 = h1 * P + t1[j];
				h2 = h2 * P +t2[j];
			}
			for (int j = r;j <= len;j++)
			{
				h1 = h1 * P + t1[j];
				h2 = h2 * P +t2[j];
				ans += mp[{h1,h2}];
			}
		}
		cout << ans << endl;
	}
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t ;t = 1;
	while (t--) {
		solvemain();
	}
	return 0;
}
/*

4 2
xabcx xadex
xabcx xadex
bc de
aaaa bbbb
aaaa bbbb
aaaa bbbb

*/
