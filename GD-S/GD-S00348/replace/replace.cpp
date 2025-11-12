//canpass: 1,2
#include <bits/stdc++.h>
#define int long long
#define rep1(i,a,b) for (int i = (a);i <= (b);i++)
using namespace std;
const int N = 5e6 + 10;
const int base = 131;
const int mod = 1e9 + 7;
int n,q;
string s,t;
vector<int> hsh1[N],hsh2[N];
vector<int> now1,now2;
int pw[N],ln[N];
int gethsh(const vector<int>& v,int l,int r)
{
	if (l > r)
		return 0;
	return (v[r] - (v[l - 1] * pw[r - l + 1] % mod) + mod) % mod;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0] = 1;
	rep1(i,1,1e6)
		pw[i] = pw[i - 1] * base % mod;
	cin >> n >> q;
	//if (n <= 200 && q <= 200)
	{
		//O(n*len*q)
		rep1(i,1,n)
		{
			cin >> s >> t;
			int len = s.size();
			ln[i] = len;
			s = ' ' + s;
			t = ' ' + t;
			hsh1[i].resize(len + 1);
			hsh1[i][0] = 0;
			rep1(j,1,len)
				hsh1[i][j] = (hsh1[i][j - 1] * base + s[j] - 'a' + 1) % mod;
			hsh2[i].resize(len + 1);
			hsh2[i][0] = 0;
			rep1(j,1,len)
				hsh2[i][j] = (hsh2[i][j - 1] * base + t[j] - 'a' + 1) % mod;
		}
		while (q--)
		{
			cin >> s >> t;
			if (s.size() != t.size())
			{
				cout << "0\n";
				continue;
			}
			int len = s.size();
			s = ' ' + s;
			t = ' ' + t;
			now1.resize(len + 1);
			now1[0] = 0;
			rep1(j,1,len)
				now1[j] = (now1[j - 1] * base + s[j] - 'a' + 1) % mod;
			now2.resize(len + 1);
			now2[0] = 0;
			rep1(j,1,len)
				now2[j] = (now2[j - 1] * base + t[j] - 'a' + 1) % mod;
			//枚举替换哪里 
			int ans = 0;
			rep1(i,1,n)
				//从j开始，用s[i]进行替换 
				for (int j = 1,k = ln[i];k <= len;j++,k++)
					//能替换
					if (gethsh(now1,j,k) == gethsh(hsh1[i],1,ln[i]))
					{
						//替换 
						if (gethsh(now1,1,j - 1) == gethsh(now2,1,j - 1) && gethsh(now2,j,k) == gethsh(hsh2[i],1,ln[i]) && gethsh(now1,k + 1,len) == gethsh(now2,k + 1,len))
						{
							ans++;
							//cout << "i=" << i << ",j=" << j << '\n';
						}
					}
			cout << ans << '\n';
		}
	}
}

